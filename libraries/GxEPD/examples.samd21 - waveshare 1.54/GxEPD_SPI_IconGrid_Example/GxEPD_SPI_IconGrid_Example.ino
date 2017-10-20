/************************************************************************************
   GxEPD_TestExample : test example for e-Paper displays from GoodDisplay.com

   based on Demo Example from GoodDisplay.com, avalable with any order for such a display, no copyright notice.

   Author : J-M Zingg

   modified by : bytecrusher

   Version : 1.1

   Support: Tested on ESP32 and waveshare 2.9inch.
*/

// include library, include base class, make path known
#include <GxEPD.h>

// select the display class to use, only one
#include <GxGDEP015OC1/GxGDEP015OC1.cpp>
//#include <GxGDE0213B1/GxGDE0213B1.cpp>
//#include <GxGDEH029A1/GxGDEH029A1.cpp>
//#include <GxGDEW027C44/GxGDEW027C44.cpp>
//#include <GxGDEW042T2/GxGDEW042T2.cpp>
//#include <GxGDEW075T8/GxGDEW075T8.cpp>

// uncomment next line for drawBitmap() test, (consumes RAM on ESP8266)
#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <imglib/gridicons_add_image.h>
#include <imglib/gridicons_add_outline.h>
#include <imglib/gridicons_add.h>
#include <imglib/gridicons_align_center.h>
#include <imglib/gridicons_align_image_center.h>
#include <imglib/gridicons_align_image_left.h>
#include <imglib/gridicons_align_image_none.h>
#include <imglib/gridicons_align_image_right.h>
#include <imglib/gridicons_align_justify.h>
#include <imglib/gridicons_align_left.h>
#include <imglib/gridicons_align_right.h>
#include <imglib/gridicons_arrow_down.h>
#include <imglib/gridicons_arrow_left.h>
#include <imglib/gridicons_arrow_right.h>
#include <imglib/gridicons_arrow_up.h>
#include <imglib/gridicons_aside.h>
#include <imglib/gridicons_attachment.h>
#include <imglib/gridicons_audio.h>
#include <imglib/gridicons_bell.h>
#include <imglib/gridicons_block.h>
#include <imglib/gridicons_bold.h>
#include <imglib/gridicons_book.h>
#include <imglib/gridicons_bookmark_outline.h>
#include <imglib/gridicons_bookmark.h>
#include <imglib/gridicons_briefcase.h>
#include <imglib/gridicons_bug.h>
#include <imglib/gridicons_calendar.h>
#include <imglib/gridicons_camera.h>
#include <imglib/gridicons_caption.h>
#include <imglib/gridicons_cart.h>
#include <imglib/gridicons_chat.h>
#include <imglib/gridicons_checkmark_circle.h>
#include <imglib/gridicons_checkmark.h>
#include <imglib/gridicons_chevron_down.h>
#include <imglib/gridicons_chevron_left.h>
#include <imglib/gridicons_chevron_right.h>
#include <imglib/gridicons_chevron_up.h>
#include <imglib/gridicons_clear_formatting.h>
#include <imglib/gridicons_clipboard.h>
#include <imglib/gridicons_cloud_download.h>
#include <imglib/gridicons_cloud_upload.h>
#include <imglib/gridicons_cloud.h>
#include <imglib/gridicons_code.h>
#include <imglib/gridicons_cog.h>
#include <imglib/gridicons_comment.h>
#include <imglib/gridicons_computer.h>
#include <imglib/gridicons_create.h>
#include <imglib/gridicons_credit_card.h>
#include <imglib/gridicons_crop.h>
#include <imglib/gridicons_cross_circle.h>
#include <imglib/gridicons_cross_small.h>
#include <imglib/gridicons_cross.h>
#include <imglib/gridicons_custom_post_type.h>
#include <imglib/gridicons_dropdown.h>
#include <imglib/gridicons_ellipsis_circle.h>
#include <imglib/gridicons_ellipsis.h>
#include <imglib/gridicons_external.h>
#include <imglib/gridicons_flag.h>
#include <imglib/gridicons_flip_horizontal.h>
#include <imglib/gridicons_flip_vertical.h>
#include <imglib/gridicons_folder_multiple.h>
#include <imglib/gridicons_folder.h>
#include <imglib/gridicons_fullscreen_exit.h>
#include <imglib/gridicons_fullscreen.h>
#include <imglib/gridicons_globe.h>
#include <imglib/gridicons_grid.h>
#include <imglib/gridicons_heading_h1.h>
#include <imglib/gridicons_heading_h2.h>
#include <imglib/gridicons_heading_h4.h>
#include <imglib/gridicons_heading.h>
#include <imglib/gridicons_heart_outline.h>
#include <imglib/gridicons_heart.h>
#include <imglib/gridicons_help_outline.h>
#include <imglib/gridicons_help.h>
#include <imglib/gridicons_history.h>
#include <imglib/gridicons_house.h>
#include <imglib/gridicons_image_multiple.h>
#include <imglib/gridicons_image.h>
#include <imglib/gridicons_indent_left.h>
#include <imglib/gridicons_indent_right.h>
#include <imglib/gridicons_info_outline.h>
#include <imglib/gridicons_info.h>
#include <imglib/gridicons_ink.h>
#include <imglib/gridicons_institution.h>
#include <imglib/gridicons_italic.h>
#include <imglib/gridicons_layout_blocks.h>
#include <imglib/gridicons_layout.h>
#include <imglib/gridicons_link_break.h>
#include <imglib/gridicons_link.h>
#include <imglib/gridicons_list_checkmark.h>
#include <imglib/gridicons_list_unordered.h>
#include <imglib/gridicons_location.h>
#include <imglib/gridicons_lock.h>
#include <imglib/gridicons_mail.h>
#include <imglib/gridicons_mention.h>
#include <imglib/gridicons_menu.h>
#include <imglib/gridicons_menus.h>
#include <imglib/gridicons_microphone.h>
#include <imglib/gridicons_minus_small.h>
#include <imglib/gridicons_minus.h>
#include <imglib/gridicons_money.h>
#include <imglib/gridicons_nametag.h>
#include <imglib/gridicons_next_page.h>
#include <imglib/gridicons_not_visible.h>
#include <imglib/gridicons_notice_outline.h>
#include <imglib/gridicons_notice.h>
#include <imglib/gridicons_offline.h>
#include <imglib/gridicons_pages.h>
#include <imglib/gridicons_pause.h>
#include <imglib/gridicons_pencil.h>
#include <imglib/gridicons_phone.h>
#include <imglib/gridicons_play.h>
#include <imglib/gridicons_plugins.h>
#include <imglib/gridicons_plus_small.h>
#include <imglib/gridicons_plus.h>
#include <imglib/gridicons_popout.h>
#include <imglib/gridicons_posts.h>
#include <imglib/gridicons_print.h>
#include <imglib/gridicons_product_downloadable.h>
#include <imglib/gridicons_product_external.h>
#include <imglib/gridicons_product_virtual.h>
#include <imglib/gridicons_product.h>
#include <imglib/gridicons_read_more.h>
#include <imglib/gridicons_reader_follow.h>
#include <imglib/gridicons_reader_following.h>
#include <imglib/gridicons_reader.h>
#include <imglib/gridicons_reblog.h>
#include <imglib/gridicons_redo.h>
#include <imglib/gridicons_refresh.h>
#include <imglib/gridicons_reply.h>
#include <imglib/gridicons_resize.h>
#include <imglib/gridicons_rotate.h>
#include <imglib/gridicons_scheduled.h>
#include <imglib/gridicons_search.h>
#include <imglib/gridicons_share_computer.h>
#include <imglib/gridicons_share_ios.h>
#include <imglib/gridicons_shipping.h>
#include <imglib/gridicons_sign_out.h>
#include <imglib/gridicons_spam.h>
#include <imglib/gridicons_speaker.h>
#include <imglib/gridicons_star_outline.h>
#include <imglib/gridicons_star.h>
#include <imglib/gridicons_stats_alt.h>
#include <imglib/gridicons_stats.h>
#include <imglib/gridicons_status.h>
#include <imglib/gridicons_sync.h>
#include <imglib/gridicons_tablet.h>
#include <imglib/gridicons_tag.h>
#include <imglib/gridicons_text_color.h>
#include <imglib/gridicons_themes.h>
#include <imglib/gridicons_thumbs_up.h>
#include <imglib/gridicons_time.h>
#include <imglib/gridicons_trash.h>
#include <imglib/gridicons_trophy.h>
#include <imglib/gridicons_types.h>
#include <imglib/gridicons_underline.h>
#include <imglib/gridicons_undo.h>
#include <imglib/gridicons_user_add.h>
#include <imglib/gridicons_user_circle.h>
#include <imglib/gridicons_user.h>
#include <imglib/gridicons_video_camera.h>
#include <imglib/gridicons_video.h>
#include <imglib/gridicons_visible.h>


#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>


#if defined(ESP8266)

// generic/common.h
//static const uint8_t SS    = 15;
//static const uint8_t MOSI  = 13;
//static const uint8_t MISO  = 12;
//static const uint8_t SCK   = 14;
// pins_arduino.h
//static const uint8_t D8   = 15;
//static const uint8_t D7   = 13;
//static const uint8_t D6   = 12;
//static const uint8_t D5   = 14;

//GxIO_SPI(SPIClass& spi, int8_t cs, int8_t dc, int8_t rst = -1, int8_t bl = -1);
GxIO_Class io(SPI, SS, D3, D4);
// GxGDEP015OC1(GxIO& io, uint8_t rst = D4, uint8_t busy = D2);
GxEPD_Class display(io);

#elif defined(ESP32)

// pins_arduino.h, e.g. LOLIN32
//static const uint8_t SS    = 5;
//static const uint8_t MOSI  = 23;
//static const uint8_t MISO  = 19;
//static const uint8_t SCK   = 18;

// GxIO_SPI(SPIClass& spi, int8_t cs, int8_t dc, int8_t rst = -1, int8_t bl = -1);
GxIO_Class io(SPI, SS, 17, 16);
// GxGDEP015OC1(GxIO& io, uint8_t rst = D4, uint8_t busy = D2);
GxEPD_Class display(io, 16, 4);

#elif defined(ARDUINO_ARCH_SAMD)

// variant.h of MKR1000
//#define PIN_SPI_MISO  (10u)
//#define PIN_SPI_MOSI  (8u)
//#define PIN_SPI_SCK   (9u)
//#define PIN_SPI_SS    (24u) // should be 4?
// variant.h of MKRZERO
//#define PIN_SPI_MISO  (10u)
//#define PIN_SPI_MOSI  (8u)
//#define PIN_SPI_SCK   (9u)
//#define PIN_SPI_SS    (4u)

GxIO_Class io(SPI, 4, 7, 6);
GxEPD_Class display(io, 6, 5);

#elif defined(_BOARD_GENERIC_STM32F103C_H_)

// STM32 Boards (STM32duino.com)
// Generic STM32F103C series
// aka BluePill
// board.h
//#define BOARD_SPI1_NSS_PIN        PA4
//#define BOARD_SPI1_MOSI_PIN       PA7
//#define BOARD_SPI1_MISO_PIN       PA6
//#define BOARD_SPI1_SCK_PIN        PA5
//enum {
//    PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13,PA14,PA15,
//  PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13,PB14,PB15,
//  PC13, PC14,PC15
//};
// variant.h
//static const uint8_t SS   = BOARD_SPI1_NSS_PIN;
//static const uint8_t SS1  = BOARD_SPI2_NSS_PIN;
//static const uint8_t MOSI = BOARD_SPI1_MOSI_PIN;
//static const uint8_t MISO = BOARD_SPI1_MISO_PIN;
//static const uint8_t SCK  = BOARD_SPI1_SCK_PIN;

//GxIO_SPI(SPIClass& spi, int8_t cs, int8_t dc, int8_t rst = -1, int8_t bl = -1);
GxIO_Class io(SPI, SS, 8, 9);
//  GxGDEP015OC1(GxIO& io, uint8_t rst = 9, uint8_t busy = 7);
GxEPD_Class display(io, 9, 3);

#else

// pins_arduino.h, e.g. AVR
#define PIN_SPI_SS    (10)
#define PIN_SPI_MOSI  (11)
#define PIN_SPI_MISO  (12)
#define PIN_SPI_SCK   (13)

GxIO_Class io(SPI, SS, 8, 9);
//GxIO_DESTM32L io;
//GxIO_GreenSTM32F103V io;
// GxGDEP015OC1(GxIO& io, uint8_t rst = 9, uint8_t busy = 7);
GxEPD_Class display(io);

#endif


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  display.init();

  Serial.println("setup done");
}

void loop()
{
  showBitmapExample();
  delay(10000);
}

void showBitmapExample()
{
#ifdef _GxBitmapExamples_H_
#ifdef _GxGDEW027C44_H_
  // draw black and red bitmap
  display.drawPicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1));
  delay(2000);
  display.setRotation(3);
#else

  display.setRotation(4);
  display.fillScreen(GxEPD_WHITE);

  
  display.drawBitmap(0, 0, gridicons_add_image, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 0, gridicons_add_outline, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 0, gridicons_add, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 0, gridicons_align_center, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 0, gridicons_attachment, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 0, gridicons_audio, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 0, gridicons_bell, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 0, gridicons_block, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 0, gridicons_bold, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 0, gridicons_book, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 0, gridicons_bookmark_outline, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 25, gridicons_align_image_center, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 25, gridicons_align_image_left, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 25, gridicons_align_image_none, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 25, gridicons_align_image_right, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 25, gridicons_bookmark, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 25, gridicons_briefcase, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 25, gridicons_bug, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 25, gridicons_calendar, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 25, gridicons_camera, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 25, gridicons_caption, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 25, gridicons_cart, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 50, gridicons_align_justify, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 50, gridicons_align_left, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 50, gridicons_align_right, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 50, gridicons_aside, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 50, gridicons_chat, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 50, gridicons_checkmark_circle, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 50, gridicons_checkmark, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 50, gridicons_chevron_down, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 50, gridicons_chevron_left, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 50, gridicons_chevron_right, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 50, gridicons_chevron_up, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 75, gridicons_arrow_left, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 75, gridicons_arrow_right, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 75, gridicons_arrow_up, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 75, gridicons_arrow_down, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 75, gridicons_clear_formatting, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 75, gridicons_clipboard, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 75, gridicons_cloud_download, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 75, gridicons_cloud_upload, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 75, gridicons_cloud, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 75, gridicons_code, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 75, gridicons_cog, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 100, gridicons_comment, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 100, gridicons_computer, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 100, gridicons_create, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 100, gridicons_credit_card, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 100, gridicons_crop, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 100, gridicons_cross_circle, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 100, gridicons_cross_small, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 100, gridicons_cross, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 100, gridicons_custom_post_type, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 100, gridicons_dropdown, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 100, gridicons_ellipsis_circle, 24, 24, GxEPD_BLACK);

  display.update();
  delay(2000);

  display.drawBitmap(0, 0, gridicons_ellipsis, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 0, gridicons_external, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 0, gridicons_flag, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 0, gridicons_flip_horizontal, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 0, gridicons_flip_vertical, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 0, gridicons_folder_multiple, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 0, gridicons_folder, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 0, gridicons_fullscreen_exit, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 0, gridicons_fullscreen, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 0, gridicons_globe, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 0, gridicons_grid, 24, 24, GxEPD_BLACK);
  
  display.drawBitmap(0, 25, gridicons_heading_h1, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 25, gridicons_heading_h2, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 25, gridicons_heading_h4, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 25, gridicons_heading, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 25, gridicons_heart_outline, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 25, gridicons_heart, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 25, gridicons_help_outline, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 25, gridicons_help, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 25, gridicons_history, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 25, gridicons_house, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 25, gridicons_image_multiple, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 50, gridicons_image, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 50, gridicons_indent_left, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 50, gridicons_indent_right, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 50, gridicons_info_outline, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 50, gridicons_info, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 50, gridicons_ink, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 50, gridicons_institution, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 50, gridicons_italic, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 50, gridicons_layout_blocks, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 50, gridicons_layout, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 50, gridicons_link_break, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 75, gridicons_link, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 75, gridicons_list_checkmark, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 75, gridicons_list_unordered, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 75, gridicons_location, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 75, gridicons_lock, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 75, gridicons_mail, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 75, gridicons_mention, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 75, gridicons_menu, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 75, gridicons_menus, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 75, gridicons_microphone, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 75, gridicons_minus_small, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 100, gridicons_minus, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 100, gridicons_money, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 100, gridicons_nametag, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 100, gridicons_next_page, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 100, gridicons_not_visible, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 100, gridicons_notice_outline, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 100, gridicons_notice, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 100, gridicons_offline, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 100, gridicons_pages, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 100, gridicons_pause, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 100, gridicons_pencil, 24, 24, GxEPD_BLACK);
  
  display.update();
  delay(2000);

  display.drawBitmap(0, 0, gridicons_phone, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 0, gridicons_play, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 0, gridicons_plugins, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 0, gridicons_plus_small, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 0, gridicons_plus, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 0, gridicons_popout, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 0, gridicons_posts, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 0, gridicons_print, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 0, gridicons_product_downloadable, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 0, gridicons_product_external, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 0, gridicons_product_virtual, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 25, gridicons_product, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 25, gridicons_read_more, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 25, gridicons_reader_follow, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 25, gridicons_reader_following, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 25, gridicons_reader, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 25, gridicons_reblog, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 25, gridicons_redo, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 25, gridicons_refresh, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 25, gridicons_reply, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 25, gridicons_resize, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 25, gridicons_rotate, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 50, gridicons_scheduled, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 50, gridicons_search, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 50, gridicons_share_computer, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 50, gridicons_share_ios, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 50, gridicons_shipping, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 50, gridicons_sign_out, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 50, gridicons_spam, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 50, gridicons_speaker, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 50, gridicons_star_outline, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 50, gridicons_star, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 50, gridicons_stats_alt, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 75, gridicons_stats, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 75, gridicons_status, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 75, gridicons_sync, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 75, gridicons_tablet, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 75, gridicons_tag, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 75, gridicons_text_color, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 75, gridicons_themes, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 75, gridicons_thumbs_up, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 75, gridicons_time, 24, 24, GxEPD_BLACK);
  display.drawBitmap(225, 75, gridicons_trash, 24, 24, GxEPD_BLACK);
  display.drawBitmap(250, 75, gridicons_trophy, 24, 24, GxEPD_BLACK);

  display.drawBitmap(0, 100, gridicons_types, 24, 24, GxEPD_BLACK);
  display.drawBitmap(25, 100, gridicons_underline, 24, 24, GxEPD_BLACK);
  display.drawBitmap(50, 100, gridicons_undo, 24, 24, GxEPD_BLACK);
  display.drawBitmap(75, 100, gridicons_user_add, 24, 24, GxEPD_BLACK);
  display.drawBitmap(100, 100, gridicons_user_circle, 24, 24, GxEPD_BLACK);
  display.drawBitmap(125, 100, gridicons_user, 24, 24, GxEPD_BLACK);
  display.drawBitmap(150, 100, gridicons_video_camera, 24, 24, GxEPD_BLACK);
  display.drawBitmap(175, 100, gridicons_video, 24, 24, GxEPD_BLACK);
  display.drawBitmap(200, 100, gridicons_visible, 24, 24, GxEPD_BLACK);

  display.update();
  delay(2000);
  
#endif
#endif
}

void showFont(const char name[], const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
#ifdef _GxGDEW027C44_H_
  display.setTextColor(GxEPD_RED);
#endif
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
  display.update();
  delay(5000);
}




