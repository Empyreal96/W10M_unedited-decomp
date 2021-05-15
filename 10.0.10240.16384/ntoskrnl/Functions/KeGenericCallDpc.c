// KeGenericCallDpc 
 
int __fastcall KeGenericCallDpc(int a1, int a2)
{
  _DWORD v3[2]; // [sp+0h] [bp-8h] BYREF

  v3[0] = a1;
  v3[1] = a2;
  return ((int (__fastcall *)(_DWORD, int (*)(), _DWORD *, int))KeGenericProcessorCallback)(
           0,
           KiGenericCallDpcWorker,
           v3,
           1);
}
