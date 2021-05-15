// KiAbApplyWakeupBoost 
 
int __fastcall KiAbApplyWakeupBoost(int result, int a2, int a3)
{
  int v5; // r6
  _DWORD *v6; // r4
  int v7; // r8
  unsigned int v8; // r7
  int v9; // r7
  unsigned int v10; // r5
  int v11; // r1
  _DWORD *v12; // [sp+10h] [bp-28h] BYREF
  int v13; // [sp+14h] [bp-24h]

  LOBYTE(v5) = result;
  if ( (*(_BYTE *)(a2 + 15) & 1) == 0 || *(_DWORD *)(a2 + 32) )
  {
    v6 = 0;
    v7 = a2 - 8 * *(unsigned __int8 *)(a2 + 12);
    v12 = 0;
    result = KfRaiseIrql(2);
    v8 = result;
    v5 = (char)v5;
    v13 = result;
    if ( (char)v5 > 15 )
      v5 = 15;
    if ( *(char *)(v7 + 347) < v5 )
    {
      v9 = 1 << (v5 - 1);
      if ( (v9 & (*(unsigned __int16 *)(a2 + 44) >> 1)) == 0 )
      {
        result = KiSetPriorityFloor(v7, &v12, v5);
        v6 = v12;
        *(_WORD *)(a2 + 44) |= 2 * (_WORD)v9;
      }
      v8 = v13;
    }
    if ( (dword_682604 & 0x200) != 0 )
    {
      result = sub_50EC80(result);
    }
    else if ( a3 )
    {
      v10 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      while ( v6 )
      {
        v11 = (int)(v6 - 36);
        v6 = (_DWORD *)*v6;
        result = KiDeferredReadyThread(v10 + 1408, v11);
      }
    }
    else
    {
      result = KiProcessDeferredReadyList(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, &v12, v8);
    }
  }
  return result;
}
