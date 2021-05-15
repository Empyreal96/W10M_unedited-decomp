// IovpUnloadDriver 
 
int __fastcall IovpUnloadDriver(int a1)
{
  int v3; // r2
  char v4[8]; // [sp+8h] [bp-38h] BYREF
  int v5[4]; // [sp+10h] [bp-30h] BYREF
  char v6[16]; // [sp+20h] [bp-20h] BYREF
  int v7; // [sp+30h] [bp-10h]

  if ( !*(_DWORD *)(a1 + 52) )
    return -1073741808;
  ObfReferenceObject(a1);
  if ( IopCheckUnloadDriver(a1, v4) >= 0 )
    return 259;
  ObfDereferenceObject(a1);
  if ( !v4[0] )
    return 259;
  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v3 == PsInitialSystemProcess )
  {
    (*(void (__fastcall **)(int))(a1 + 52))(a1);
  }
  else
  {
    KeInitializeEvent((int)v6, 0, 0);
    v5[2] = (int)IopLoadUnloadDriver;
    v5[3] = (int)v5;
    v5[0] = 0;
    v7 = a1;
    ExQueueWorkItem(v5, 1);
    KeWaitForSingleObject((unsigned int)v6, 0, 0, 0, 0);
  }
  ObMakeTemporaryObject(a1);
  ObfDereferenceObject(a1);
  return 0;
}
