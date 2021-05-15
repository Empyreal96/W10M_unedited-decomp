// IopDeviceRemovalForResetComplete 
 
unsigned int __fastcall IopDeviceRemovalForResetComplete(unsigned int a1)
{
  __int64 v2; // kr00_8
  unsigned int v3; // r2
  __int64 v4; // r2
  unsigned int result; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r1

  v2 = *(_QWORD *)(a1 + 100);
  if ( (int)v2 >= 0 || !*(_DWORD *)(a1 + 96) )
  {
    if ( *(_DWORD *)(HIDWORD(v2) + 24) && *(_DWORD *)(HIDWORD(v2) + 28) )
    {
      if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
        goto LABEL_8;
    }
    else if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
    {
LABEL_8:
      Template_hzr0qqhzr4(Microsoft_Windows_Kernel_PnPHandle, dword_649E54);
      goto LABEL_9;
    }
  }
LABEL_9:
  if ( (int)v2 >= 0 || (v3 = *(_DWORD *)(a1 + 108), v3 >= PnpResetMaximumRetryAttempts) )
  {
    result = ExFreePoolWithTag(a1);
    __dmb(0xBu);
    v6 = (unsigned int *)(HIDWORD(v2) + 32);
    do
    {
      v7 = __ldrex(v6);
      v8 = v7 - 1;
    }
    while ( __strex(v8, v6) );
    __dmb(0xBu);
    if ( !v8 )
      result = ExFreePoolWithTag(HIDWORD(v2));
  }
  else
  {
    *(_DWORD *)(a1 + 108) = v3 + 1;
    v4 = PnpResetRetryInterval;
    *(_DWORD *)(a1 + 96) = v2;
    result = KiSetTimerEx(a1, a1 + 48, v4, 0, 0, a1 + 48);
  }
  return result;
}
