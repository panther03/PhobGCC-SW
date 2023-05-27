#ifndef USB_H_
#define USB_H_

#include "structsAndEnums.h"
#include "tusb.h"

void tud_mount_cb(void);

void tud_umount_cb(void);

void tud_suspend_cb(bool remote_wakeup_en);

void tud_resume_cb(void);

void tud_hid_report_complete_cb(uint8_t instance, uint8_t const *report,
                                uint16_t len);

uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id,
                               hid_report_type_t report_type, uint8_t *buffer,
                               uint16_t reqlen);

void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id,
                           hid_report_type_t report_type, uint8_t const *buffer,
                           uint16_t bufsize);

hid_gamepad_report_t convertGCCtoHIDReport(Buttons& _btn);

static void send_hid_report(Buttons& _btn);

uint16_t send_custom_report(uint8_t cmd);

void hid_task(Buttons& _btn);

void usb_init_comms();

void usb_run_comms(Buttons& _btn);

#endif /* USB_H_ */