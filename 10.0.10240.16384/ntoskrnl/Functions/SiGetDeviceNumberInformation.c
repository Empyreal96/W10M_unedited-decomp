// SiGetDeviceNumberInformation 
 
int __fastcall SiGetDeviceNumberInformation(unsigned __int16 *a1, _DWORD *a2, _DWORD *a3)
{
  int v5; // r4
  char v7[8]; // [sp+58h] [bp-28h] BYREF
  int v8; // [sp+60h] [bp-20h]
  int v9; // [sp+64h] [bp-1Ch]
  int v10; // [sp+68h] [bp-18h]

  RtlInitUnicodeString((unsigned int)v7, a1);
  v5 = ZwOpenFile();
  if ( v5 >= 0 )
  {
    v5 = ZwCreateEvent();
    if ( v5 >= 0 )
    {
      ZwResetEvent();
      v5 = ZwDeviceIoControlFile();
      if ( v5 == 259 )
      {
        v5 = ZwWaitForSingleObject();
        if ( v5 < 0 )
          return v5;
        v5 = 0;
      }
      if ( v5 >= 0 )
      {
        if ( v8 == 7 )
        {
          *a2 = v9;
          *a3 = v10;
        }
        else
        {
          v5 = -1073741637;
        }
      }
    }
  }
  return v5;
}
