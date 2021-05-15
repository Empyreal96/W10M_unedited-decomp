// EtwpTraceHandle 
 
int __fastcall EtwpTraceHandle(int result, int a2, int a3, int a4)
{
  int v4; // r2
  unsigned int v5; // r6
  unsigned int v6; // r5
  int v7; // r9
  unsigned int v8; // r7
  unsigned int v9; // r4
  unsigned __int16 *v10; // lr
  int v11; // t1
  unsigned int v12; // r1
  int v13; // r2
  int v14; // r7
  int v15; // r6
  int v16; // r5
  char *v17; // r4
  int v18; // r2
  int v19; // r0
  int v20; // r2
  int v21; // r3
  int *v22; // r1
  int i; // [sp+8h] [bp-188h] BYREF
  int v24; // [sp+Ch] [bp-184h] BYREF
  int v25; // [sp+10h] [bp-180h]
  int v26; // [sp+14h] [bp-17Ch]
  int v27; // [sp+18h] [bp-178h]
  int v28; // [sp+1Ch] [bp-174h]
  int v29; // [sp+20h] [bp-170h]
  int v30; // [sp+24h] [bp-16Ch] BYREF
  _DWORD v31[2]; // [sp+28h] [bp-168h] BYREF
  __int16 v32; // [sp+30h] [bp-160h]
  int v33[12]; // [sp+38h] [bp-158h] BYREF
  char v34[296]; // [sp+68h] [bp-128h] BYREF

  v28 = a3;
  v29 = a4;
  v4 = *(_DWORD *)(a4 + 132);
  v5 = EtwpActiveSystemLoggers;
  v26 = a2;
  v27 = result;
  v6 = __clz(__rbit(EtwpActiveSystemLoggers));
  v25 = v4;
  v7 = 0;
  if ( 1 != (unsigned __int8)(v6 >> 5) )
  {
    do
    {
      v5 &= v5 - 1;
      if ( &EtwpGroupMasks[8 * v6] )
      {
        if ( (EtwpGroupMasks[8 * v6 + 4] & 0x40) != 0 )
        {
          v8 = EtwpObjectTypeFilter[10 * v6];
          v9 = 0;
          if ( EtwpObjectTypeFilter[10 * v6] )
          {
            v24 = v4;
            v10 = &EtwpObjectTypeFilter[10 * v6];
            do
            {
              v11 = *((_DWORD *)v10 + 1);
              v10 += 2;
              v12 = 0;
              v13 = 0;
              v30 = v11;
              while ( 1 )
              {
                result = *((unsigned __int8 *)&v30 + v13);
                if ( result == 42 )
                {
LABEL_13:
                  v7 |= 1 << v6;
                  goto LABEL_14;
                }
                if ( result != 63
                  && (v12 != 3 || (*((_BYTE *)&v24 + v13) & 0x7F) != result)
                  && *((unsigned __int8 *)&v24 + v13) != result )
                {
                  break;
                }
                ++v12;
                ++v13;
                if ( v12 >= 4 )
                  goto LABEL_13;
              }
              ++v9;
            }
            while ( v9 < v8 );
LABEL_14:
            v4 = v25;
          }
        }
      }
      v6 = __clz(__rbit(v5));
    }
    while ( 1 != (unsigned __int8)(v6 >> 5) );
    if ( v7 )
    {
      v14 = v27;
      v15 = v28;
      v16 = 1;
      v31[0] = v28;
      v31[1] = v26;
      v17 = v34;
      v32 = *(unsigned __int8 *)(v29 + 20);
      v33[0] = (int)v31;
      v33[1] = 0;
      v33[2] = 10;
      v33[3] = 0;
      if ( v27 == 4385 )
      {
        v18 = 264;
        for ( i = 264; ; v18 = i )
        {
          v19 = ObQueryNameStringMode(v15, (int)v17, v18, &i, 0);
          if ( v19 != -1073741820 )
            break;
          if ( v17 != v34 )
            ExFreePoolWithTag((unsigned int)v17);
          v17 = (char *)ExAllocatePoolWithTag(1, i, 1953985605);
          if ( !v17 )
            goto LABEL_30;
        }
        if ( !v19 )
        {
          v20 = 0x2000;
          if ( *(unsigned __int16 *)v17 < 0x2000u )
            v20 = *(unsigned __int16 *)v17;
          v21 = *((_DWORD *)v17 + 1);
          v33[6] = v20;
          v33[4] = v21;
          v33[5] = 0;
          v33[7] = 0;
          v16 = 2;
        }
      }
LABEL_30:
      v22 = &v33[4 * v16];
      *v22 = (int)&EtwpNull;
      v22[1] = 0;
      v22[2] = 2;
      v22[3] = 0;
      result = EtwpTraceKernelEventWithFilter((int)v33, v16 + 1, v7, v14, 273684738);
      if ( v17 )
      {
        if ( v17 != v34 )
          result = ExFreePoolWithTag((unsigned int)v17);
      }
    }
  }
  return result;
}
