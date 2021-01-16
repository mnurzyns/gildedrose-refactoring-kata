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
        if (items[i].name != sulfuras) // for items that change their quality; Sulfuras doesn't
        {
            if(items[i].sellIn < 0 || items[i].sellIn == 0) // when dealing with "changable" elements and sellIn < 0 or == 0
            {
                if(items[i].name==aged)
                { 
                    items[i].quality += 2; items[i].sellIn -= 1; 
                    if(items[i].quality > 50) { items[i].quality = 50; }
                }
                else if(items[i].name==backstage)
                { items[i].quality = 0; items[i].sellIn -= 1; }
                else { items[i].sellIn -=1; items[i].quality -=2; }
            }
            else if (items[i].quality > 0 && items[i].quality < 50) // quality in range (0,50)
            {
                if(items[i].name == aged) { items[i].sellIn -= 1; items[i].quality += 1; }
                else if(items[i].name == backstage)
                { 
                    if(items[i].sellIn < 1) { items[i].quality = 0; items[i].sellIn -= 1; } // if less than 1 (0 and less) - after concert
                    else if(items[i].sellIn < 6 && items[i].quality+3 < 51 ) { items[i].quality +=3; items[i].sellIn -=1; }
                    else if(items[i].sellIn < 11 && items[i].quality+2 < 51 ) { items[i].quality +=2; items[i].sellIn -=1; }
                }
                else { items[i].quality -=1; items[i].sellIn -=1; } // for regular items
            }
            else if(items[i].quality == 0 || items[i].quality == 50 )
                if(items[i].name == aged || items[i].name != backstage) // aged brie and regular ones; do not change the quality
                    items[i].sellIn -=1; 
        }
    }
}
