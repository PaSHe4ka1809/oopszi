using System;
using System.Collections.Generic;
using System.Text;

namespace Bridges.DomainObjects
{
    public class BridgeInformation : DomainObject
    {
        public string Name { get; set; }

        public string Location { get; set; }

        public string Intersection { get; set; }

        public int Year { get; set; }

    }
}
