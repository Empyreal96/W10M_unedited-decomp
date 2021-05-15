// KeSetIdealProcessorThread 
 
int __fastcall KeSetIdealProcessorThread(int a1, unsigned __int8 a2, int a3, int a4)
{
  __int16 v4; // r3
  int v6; // [sp+0h] [bp-8h] BYREF
  int v7; // [sp+4h] [bp-4h]

  v6 = a3;
  v7 = a4;
  if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    v4 = *(_WORD *)(a1 + 360);
  else
    v4 = *(_WORD *)(a1 + 344);
  LOWORD(v6) = v4;
  HIWORD(v6) = a2;
  KeSetIdealProcessorThreadByNumber(a1, &v6);
  return BYTE2(v7);
}
