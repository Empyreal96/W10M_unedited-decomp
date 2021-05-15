// PoInitDriverServices 
 
int PoInitDriverServices()
{
  unsigned __int16 v1[4]; // [sp+10h] [bp-8h] BYREF

  IoRegisterPlugPlayNotification(
    2,
    0,
    (void **)&GUID_DEVICE_THERMAL_ZONE,
    PnpDriverObject,
    (int)PopNotifyPolicyDevice,
    1,
    v1);
  IoRegisterPlugPlayNotification(
    2,
    0,
    (void **)&GUID_DEVICE_BATTERY,
    PnpDriverObject,
    (int)PopNotifyPolicyDevice,
    2,
    v1);
  IoRegisterPlugPlayNotification(2, 0, (void **)&GUID_DEVICE_MEMORY, PnpDriverObject, (int)PopNotifyPolicyDevice, 3, v1);
  IoRegisterPlugPlayNotification(
    2,
    0,
    (void **)&GUID_DEVICE_ACPI_TIME,
    PnpDriverObject,
    (int)PopNotifyPolicyDevice,
    8,
    v1);
  return IoRegisterPlugPlayNotification(
           2,
           0,
           (void **)&GUID_DEVICE_FAN,
           PnpDriverObject,
           (int)PopNotifyPolicyDevice,
           9,
           v1);
}
