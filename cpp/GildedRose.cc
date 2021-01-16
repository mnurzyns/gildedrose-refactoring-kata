#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

static std::string aged = "Aged Brie";
static std::string backstage = "Backstage passes to a TAFKAL80ETC concert";
static std::string sulfuras = "Sulfuras, Hand of Ragnaros";

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != aged && items[i].name != backstage && items[i].name != sulfuras)
        {
            if (items[i].quality > 0) items[i].quality -= 1;        
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality += 1;

                if (items[i].name == backstage)
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                            items[i].quality += 1;
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                            items[i].quality += 1;
                    }
                }
            }
        }

        if (items[i].name != sulfuras)
            items[i].sellIn -= 1;

        if (items[i].sellIn < 0)
        {
            if (items[i].name != aged)
            {
                if (items[i].name != backstage)
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != sulfuras)
                            items[i].quality -= 1;
                    }
                }
                else
                    items[i].quality -= items[i].quality;
            }
            else
            {
                if (items[i].quality < 50)
                    items[i].quality += 1;
            }
        }
    }
}
