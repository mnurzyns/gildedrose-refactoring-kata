#include "GildedRose.h"
#include <string>

GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    std::string name1 = "Aged Brie";
    std::string name2 = "Backstage passes to a TAFKAL80ETC concert";
    std::string name3 = "Sulfuras, Hand of Ragnaros";

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != name1 && items[i].name != name2 && items[i].name != name3)
        {
            if (items[i].quality > 0)
            {
                --items[i].quality;
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                ++items[i].quality;

                if (items[i].name == name2)
                {
                    if (items[i].sellIn < 11)
                    {
                        ++items[i].quality; 
                    }

                    if (items[i].sellIn < 6)
                    {
                        ++items[i].quality;
                    }
                }
            }
        }

        if (items[i].name != name3)
        {
            --items[i].sellIn;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != name1)
            {
                if (items[i].name != name2)
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != name3)
                        {
                            --items[i].quality;
                        }
                    }
                }

                if(items[i].name == name2)
                {
                    items[i].quality=0;
                }
            }

            if (items[i].quality < 50 && items[i].name == name1)
            {
                ++items[i].quality;
            }
        }
    }
}
