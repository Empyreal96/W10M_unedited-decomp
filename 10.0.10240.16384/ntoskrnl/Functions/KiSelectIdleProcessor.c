// KiSelectIdleProcessor 
 
int __fastcall KiSelectIdleProcessor(int a1, int a2, _DWORD *a3, int a4)
{
  int v4; // r4
  int v8; // r1
  int result; // r0
  char v10; // r2
  int v11; // r1
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  v4 = a4;
  if ( !a4 )
  {
    v8 = a3[65] & a1;
    if ( !v8 )
      return 0;
    v10 = *((_BYTE *)*(&KiProcessorBlock + a3[36]) + 1053);
    v4 = (int)*(&KiProcessorBlock + (((unsigned __int8)__clz(__rbit(__ROR4__(v8, v10))) + v10) & 0x1F));
  }
  result = 0;
  v11 = *a3 & a1;
  v12[0] = v11;
  if ( v11 )
  {
    if ( *(_DWORD *)(v4 + 1048) != *(_DWORD *)(v4 + 3468) )
    {
      if ( (a3[1] & v11) != 0 )
      {
        v11 &= a3[1];
      }
      else if ( *(_DWORD **)(a2 + 2360) == a3 )
      {
        KiReduceByEffectiveIdleSmtSet(a2, v12);
        v11 = v12[0];
      }
    }
    if ( (*(_DWORD *)(v4 + 1048) & v11) != 0 )
    {
      result = v4;
    }
    else
    {
      if ( (*(_DWORD *)(v4 + 3468) & v11) != 0 )
        v11 &= *(_DWORD *)(v4 + 3468);
      result = (int)*(&KiProcessorBlock
                    + (((unsigned __int8)__clz(__rbit(__ROR4__(v11, *(_BYTE *)(v4 + 1053)))) + *(_BYTE *)(v4 + 1053)) & 0x1F));
    }
  }
  return result;
}
