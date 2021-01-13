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
        //everything but name 1,2,3
        if (items[i].name != name1 && items[i].name != name2 && items[i].name != name3)
        {
            if (items[i].quality > 0)
            {
                --items[i].quality;
            }
        }
        else//name 1, 2 and 3
        {
            if (items[i].quality < 50)
            {
                ++items[i].quality;//name1 + 1 q

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


        //everything but name 3
        if (items[i].name != name3)
        {
            --items[i].sellIn; //name1 - 1 sellIn
        }

        //everything but name 1,2,3
        if (items[i].name != name1 && items[i].name != name2 && items[i].quality > 0 && items[i].name != name3)
        {
            if (items[i].sellIn < 0)
            {        
                --items[i].quality;
            }
        }

        //name 1
        if(items[i].sellIn < 0 && items[i].quality < 50 && items[i].name == name1)
        {
            ++items[i].quality;
        }

        //name 2
        if(items[i].name == name2)
        {
            if(items[i].sellIn < 0)
            {
                items[i].quality = 0;
            }
        }
    }
}
