using System;
using System.Collections.Generic;
using System.Linq;


namespace AdventOfCode7
{
    class Program
    {
        static void Main(string[] args)
        {
            var bagRules = GetBagRules(ReadFile());
            Console.WriteLine("Count: " + GetCount1(bagRules, "shiny gold"));
            Console.WriteLine("Count: " + GetCount2(bagRules, bagRules.First(r => r.BagName == "shiny gold")));
        }

        public static List<string> ReadFile()
        {
            return System.IO.File.ReadAllLines(@"/home/smoodle/Misc/Programming/AdventOfCode/7/input.txt").ToList();
        }

        public static List<BagRule> GetBagRules(List<string> lines)
        {
            string[] separatingStrings = { "bags contain", "bag,", "bags,", "bag.", "bags." };
            List<BagRule> bagRules = new List<BagRule>();
            foreach (var line in lines)
            {
                string[] words = line.Split(separatingStrings, StringSplitOptions.RemoveEmptyEntries);
                BagRule bagRule = new BagRule();
                bagRule.BagName = words[0].Trim();
                for (int i = 1; i < words.Length; i++)
                {
                    string rule = words[i].Trim();
                    if (!string.Equals("no other", rule))
                    {
                        bagRule.Contents.Add(rule.Substring(1).Trim(), int.Parse(rule.Substring(0, 1)));
                    }
                }
                bagRules.Add(bagRule);
            }

            return bagRules;
        }

        public static int GetCount1(List<BagRule> bagRules, string bagOnSearch, BagRule currBag = null)
        {
            var count = 0;
            if (currBag != null)
            {
                if (currBag.BagName == bagOnSearch)
                {
                    return 1;
                }

                if (currBag.Contents.Count == 0)
                {
                    return 0;
                }

                if (currBag.Contents.ContainsKey(bagOnSearch))
                {
                    return 1;
                }

                foreach (var keyValuePair in currBag.Contents)
                {
                    var result = GetCount1(bagRules, bagOnSearch, bagRules.First(b => b.BagName == keyValuePair.Key));
                    if(result >= 1)
                    {
                        return 1;
                    }
                }

                return count;
            }
            else
            {
                foreach (var bagRule in bagRules)
                {
                    count += GetCount1(bagRules, bagOnSearch, bagRule);
                }
            }

            return count;
        }

        public static int GetCount2(List<BagRule> bagRules, BagRule currBag)
        {
            var count = 0;
            if (currBag != null)
            {
                if (currBag.Contents.Count == 0)
                {
                    return 1;
                }

                foreach (var keyValuePair in currBag.Contents)
                {
                    count += keyValuePair.Value * GetCount2(bagRules, bagRules.First(b => b.BagName == keyValuePair.Key));
                    if(bagRules.Find(a => a.BagName == keyValuePair.Key).Contents.Count != 0)
                        count += keyValuePair.Value;
                }

                foreach (var keyValuePair in currBag.Contents)
                {
                    
                }

                return count;
            }

            return count;
        }
    }

    public class BagRule
    {
        public string BagName { get; set; }

        public Dictionary<string, int> Contents { get; set; } = new Dictionary<string, int>();
    }
}
