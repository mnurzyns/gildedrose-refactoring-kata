#include "GildedRose.h"


GildedRose::GildedRose(::std::vector < Item >
  const & items): items(items) {}

GildedRose::GildedRose(::std::vector < Item > && items): items(::std::move(items)) {}

void GildedRose::updateQuality() {
  std::string x = "Backstage passes to a TAFKAL80ETC concert";
  std::string y = "Sulfuras, Hand of Ragnaros";
  std::string z = "Aged Brie";
  for (int i = 0; i < items.size(); i++) {

    if (items[i].quality > 0) {

      if (items[i].name != z && items[i].name != x) {
        if (items[i].name != y) {
          items[i].quality--;
        }
      } else {
        if (items[i].quality < 50) {
          items[i].quality++;

          if (items[i].name == x) {
            if (items[i].sellIn < 11) {

              items[i].quality++;

            }

            if (items[i].sellIn < 6) {
              items[i].quality++;
            }
          }
        }
      }

    }
    if (items[i].name != y) {
      items[i].sellIn--;
    }

    if (items[i].sellIn < 0) {
      if (items[i].name != z) {
        if (items[i].name != x) {
          if (items[i].quality > 0 && items[i].name != y) {

            items[i].quality--;

          }
        } else {
          items[i].quality = 0;
        }
      } else {
        if (items[i].quality < 50) {
          items[i].quality++;
        }
      }
    }

  }
}
