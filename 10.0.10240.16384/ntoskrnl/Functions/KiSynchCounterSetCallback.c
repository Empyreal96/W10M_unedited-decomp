// KiSynchCounterSetCallback 
 
int __fastcall KiSynchCounterSetCallback(int a1, int a2)
{
  int v2; // r7
  int v3; // r5
  unsigned int v4; // r6
  void **v5; // r8
  int result; // r0
  char v7[8]; // [sp+10h] [bp-38h] BYREF
  unsigned __int16 v8[24]; // [sp+18h] [bp-30h] BYREF

  if ( !a1 )
  {
    EtwReferenceSpinLockCounters();
    return 0;
  }
  if ( a1 == 1 )
  {
    EtwDereferenceSpinLockCounters();
    return 0;
  }
  if ( a1 != 2 && a1 != 3 )
    return 0;
  v2 = *(_DWORD *)(a2 + 20);
  v3 = 0;
  v4 = KeNumberProcessors_0;
  if ( !KeNumberProcessors_0 )
    return 0;
  v5 = &KiProcessorBlock;
  while ( 1 )
  {
    ++v5;
    RtlStringCbPrintfW(v8, 0x16u, (int)L"%u", v3);
    RtlInitUnicodeString((unsigned int)v7, v8);
    result = PcwAddInstance(v2, (int)v7, v3, 1);
    if ( result < 0 )
      break;
    if ( ++v3 >= v4 )
      return 0;
  }
  return result;
}
