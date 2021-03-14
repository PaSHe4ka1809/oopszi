using Bridges.WebService.Data.Models;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Net;

namespace Bridges.WebService.Controllers
{
    public class BridgesController : ControllerBase
    { 
    [HttpGet("api/[controller]/GetCurrent")]

        public ActionResult GetCurrent()
        {
            string json = "";
            try 
            {
            using (StreamReader sr = new StreamReader("DataFile.json"))
            {
            json = sr.ReadToEnd();
            }
            }
            catch (Exception ex)
            {
            return BadRequest("Не удалось получить доступ к файлу \"DataFile.json\"");    
            }
        
            if (String.IsNullOrEmpty(json))
            {
            return NotFound("Нет данных для вывода в файле \"DataFile.json\"");
            }

            return Ok(json);
        }
        [HttpGet("api/[controller]/Post")]
        public ActionResult Post()
        {
            int current_count = 0, count = 0;
            try
            {
                using (StreamReader sr = new StreamReader("DataCount.txt"))
                {
                    current_count = int.Parse(sr.ReadToEnd());
                }
            }
            catch (Exception ex)
            {
                using (StreamWriter sw = new StreamWriter("DataCount.txt", false, System.Text.Encoding.Default))
                {
                    sw.WriteLine(0);
                }
            }
            try
            {
                string url_count = "https://apidata.mos.ru/v1/datasets/2069/count/?api_key=bd78f248342dc0921a9447a36393f6f5";
                HttpWebRequest Request_count = (HttpWebRequest)WebRequest.Create(url_count);
                HttpWebResponse Response_count = (HttpWebResponse)Request_count.GetResponse();
                using (StreamReader sr = new StreamReader(Response_count.GetResponseStream()))
                {
                    count = int.Parse(sr.ReadToEnd());
                }
            }
            catch (Exception ex)
            {
                return BadRequest("Произошла ошибка при получении даных/n" + ex.Message);
            }
            if (current_count < count)
            {
                try
                {
                    using (StreamWriter sw = new StreamWriter("DataCount.txt", false, System.Text.Encoding.Default))
                    {
                        sw.WriteLine(count);
                    }
                    string url_data = "https://apidata.mos.ru/v1/datasets/2069/rows/?api_key=bd78f248342dc0921a9447a36393f6f5";
                    string data = "";
                    HttpWebRequest Request_data = (HttpWebRequest)WebRequest.Create(url_data);
                    HttpWebResponse Response_data = (HttpWebResponse)Request_data.GetResponse();
                    using (StreamReader streamreader = new StreamReader(Response_data.GetResponseStream()))
                    {
                        data = streamreader.ReadToEnd();
                    }
                    List<Bridge> Deser_obj = JsonConvert.DeserializeObject<List<Bridge>>(data);
                    using (StreamWriter sw = new StreamWriter("DataFile.json", false, System.Text.Encoding.Default))
                    {
                        string jsonfile = JsonConvert.SerializeObject(Deser_obj, Formatting.Indented);
                        sw.WriteLine(jsonfile);
                    }
                }
                catch (Exception ex)
                {
                    return BadRequest("Произошла ошибка при получении даных/n" + ex.Message);
                }
            }
            return Ok("Данные обновлены");
        }
    }
}
