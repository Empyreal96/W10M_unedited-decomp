// KiConfigureProcessorBlock 
 
_DWORD *__fastcall KiConfigureProcessorBlock(_DWORD *result)
{
  int v1; // r4
  int v2; // r2
  unsigned int v3; // r1
  int v4; // r2
  __int16 v5; // r1
  int v6; // r2
  void **v7; // r4
  int v8; // r5
  _DWORD *v9; // r1
  int v10; // t1
  unsigned int v11; // [sp+0h] [bp-10h]

  v1 = result[590];
  v2 = (1 << result[5]) | *(_DWORD *)(v1 + 260);
  v3 = __clz(__rbit(v2));
  *(_DWORD *)(v1 + 260) = v2;
  v11 = 31 - __clz(v2);
  *(_DWORD *)(v1 + 280) = v3;
  v4 = *(_DWORD *)(v1 + 260);
  *(_DWORD *)(v1 + 144) = v3;
  *(_DWORD *)(v1 + 284) = v11;
  v5 = *(_WORD *)(v1 + 266);
  if ( ((v4 - 1) & v4) == 0 )
  {
    result = 0;
    v6 = (unsigned __int16)KeNumberNodes;
    if ( KeNumberNodes )
    {
      v7 = &KeNodeBlock;
      v8 = 1 << v5;
      do
      {
        v10 = (int)*v7++;
        v9 = (_DWORD *)v10;
        if ( !*(_WORD *)(v10 + 264) )
        {
          if ( !result )
            result = v9;
          v9[64] = result[64] | v8;
        }
        --v6;
      }
      while ( v6 );
    }
  }
  return result;
}
