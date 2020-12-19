#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    const std::string AGEDBRIE = "Aged Brie";
    const std::string BACKSTAGEPASS = "Backstage passes to a TAFKAL80ETC concert";
    const std::string SULFURAS = "Sulfuras, Hand of Ragnaros";
    
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != AGEDBRIE && items[i].name != BACKSTAGEPASS && items[i].name != SULFURAS)
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

                if (items[i].name == BACKSTAGEPASS)
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

        if (items[i].name != SULFURAS)
        {
            --items[i].sellIn;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != AGEDBRIE)
            {
                if (items[i].name != BACKSTAGEPASS)
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != SULFURAS)
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
