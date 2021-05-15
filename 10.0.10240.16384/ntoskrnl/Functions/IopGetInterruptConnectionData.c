// IopGetInterruptConnectionData 
 
int __fastcall IopGetInterruptConnectionData(int a1, _DWORD *a2)
{
  int v4; // r5
  _DWORD *v5; // r4
  unsigned int v7; // [sp+10h] [bp-18h]

  *a2 = 0;
  v4 = IoGetDevicePropertyData(a1, INTERRUPT_CONNECTION_DATA_PKEY, 0);
  if ( v4 == -1073741789 && v7 >= 0x50 )
  {
    v5 = (_DWORD *)ExAllocatePoolWithTag(512, v7, 1869181008);
    if ( v5 )
    {
      v4 = IoGetDevicePropertyData(a1, INTERRUPT_CONNECTION_DATA_PKEY, 0);
      if ( v4 < 0 )
        JUMPOUT(0x7DF066);
      if ( v7 < 72 * (*v5 - 1) + 80 )
        return sub_7DF064();
      *a2 = v5;
    }
    else
    {
      v4 = -1073741670;
    }
  }
  return v4;
}
