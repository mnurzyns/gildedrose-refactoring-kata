#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}
 

void GildedRose::updateQuality()
{
    std::string name;
    int quality, sellIn;

    std::string aged = "Aged Brie";
    std::string sulfuras = "Sulfuras, Hand of Ragnaros";
    std::string backstage = "Backstage passes to a TAFKAL80ETC concert";
    

    for (int i = 0; i < items.size(); i++)
    {
        name = items[i].name;
        quality = items[i].quality;
        sellIn = items[i].sellIn;

        if (name != aged && name != backstage && name != sulfuras)
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

                if (name == backstage)
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

        if (name != sulfuras)
        {
            --items[i].sellIn;
        }

        if (items[i].sellIn < 0)
        {
            if (name != aged)
            {
                if (name != backstage)
                {
                    if (items[i].quality > 0)
                    {
                        if (name != sulfuras)
                        {
                            --items[i].quality;
                        }
                    }
                }
                else
                {
                    items[i].quality=0;
                }
            }
            else if (items[i].quality < 50)
            {
                ++items[i].quality;
            }
        }
    }
}
