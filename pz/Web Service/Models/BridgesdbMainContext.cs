using Microsoft.EntityFrameworkCore;

namespace Web_Service.Models
{
    public class BridgesdbMainContext : DbContext
    {
        public BridgesdbMainContext()
        {
        }

        public DbSet<BridgeInfo> Bridges { get; set; }

        public BridgesdbMainContext(DbContextOptions<BridgesdbMainContext> options)
            : base(options)
        {
            //Database.EnsureDeleted();
            Database.EnsureCreated();           
        }
    }
}