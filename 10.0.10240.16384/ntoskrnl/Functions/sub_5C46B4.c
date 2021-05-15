// sub_5C46B4 
 
int __fastcall sub_5C46B4(int a1, int a2)
{
  unsigned __int64 v3; // r2
  unsigned int v4; // r2
  unsigned int v5; // r2
  int result; // r0

  _rt_udiv64(10i64, *(_QWORD *)(a2 + 72));
  if ( v3 <= 9 )
  {
    switch ( (_DWORD)v3 )
    {
      case 5:
        RtlWriteTryAcquireTickLock();
        break;
      case 6:
        KfRaiseIrql(2);
        break;
      case 7:
        v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v5 + 308);
        break;
      case 8:
        v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v4 + 310);
        break;
      case 9:
        __disable_irq();
        break;
    }
  }
  KiInitializeExternalCacheController(__ROR4__(2120, 3), *(_DWORD *)(a2 + 40), *(_DWORD *)(a2 + 48));
  return result;
}
