#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != "Aged Brie" && items[i].name != "Backstage passes to a TAFKAL80ETC concert" && items[i].name != "Sulfuras, Hand of Ragnaros")
        {
            --items[i].sellIn;

            if (items[i].quality > 0)
            {
                --items[i].quality;
                if (items[i].sellIn < 0)
                {
                    --items[i].quality;
                }
            }
        }
        else //aged, sulfas, backstage
        {
            if (items[i].quality < 50)
            {
                ++items[i].quality;

                if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
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

            if (items[i].name != "Sulfuras, Hand of Ragnaros")
            {
                --items[i].sellIn;
            }
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
            {
                items[i].quality = 0;
            }

            if (items[i].quality < 50 && items[i].name == "Aged Brie")
            {
                ++items[i].quality;
            }
        }
    }
}
