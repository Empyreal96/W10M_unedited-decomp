// KiInitializeDynamicProcessor 
 
int __fastcall KiInitializeDynamicProcessor(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v7; // [sp+0h] [bp-18h]
  int v8; // [sp+8h] [bp-10h] BYREF
  int v9; // [sp+Ch] [bp-Ch]

  v7 = a1;
  v9 = a4;
  v8 = a1;
  __dmb(0xBu);
  LOBYTE(v9) = 0;
  KeGenericCallDpc((int)KiInitializeDynamicProcessorDpc, (int)&v8);
  if ( KeThreadDpcEnable )
  {
    v5 = KiStartDpcThread(a1);
    if ( v5 < 0 )
      KeBugCheckEx(51, v5, 0, 0, 0);
  }
  return v7;
}
