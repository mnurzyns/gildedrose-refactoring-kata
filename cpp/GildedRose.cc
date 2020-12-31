#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    using std::string;
    const string brie = "Aged Brie";
    const string concert = "Backstage passes to a TAFKAL80ETC concert";
    const string sulfuras = "Sulfuras, Hand of Ragnaros";
    
    for(int i = 0; i < items.size(); i++)
    {
        if     ( items[i].isRegularItem && items[i].quality > 0) --items[i].quality;
        else if(!items[i].isRegularItem && items[i].quality < 50)
        {
            ++items[i].quality;

            if(items[i].name == concert && items[i].sellIn < 6) ++items[i].quality;
            if(items[i].name == concert && items[i].sellIn < 11) ++items[i].quality;
        }

        if(items[i].name != sulfuras) --items[i].sellIn;

        if(items[i].sellIn < 0)
        {
            if     (items[i].isRegularItem && items[i].quality > 0) --items[i].quality;
            else if(items[i].name != brie  &&(items[i].name == concert || items[i].name
                == sulfuras || items[i].quality <= 0)) items[i].quality = 0;
                
            else if(items[i].name == brie  && items[i].quality < 50) ++items[i].quality;
        }
    }
}
