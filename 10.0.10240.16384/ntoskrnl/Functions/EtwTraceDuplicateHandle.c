// EtwTraceDuplicateHandle 
 
unsigned int __fastcall EtwTraceDuplicateHandle(unsigned int result, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r2
  unsigned int v7; // r7
  int v8; // r6
  unsigned int v9; // r5
  unsigned int v10; // r8
  unsigned int v11; // r4
  unsigned __int16 *v12; // lr
  int v13; // t1
  int v14; // r2
  int v15; // r1
  int v16; // [sp+8h] [bp-68h] BYREF
  int v17; // [sp+Ch] [bp-64h]
  unsigned int v18; // [sp+10h] [bp-60h]
  int v19; // [sp+14h] [bp-5Ch]
  int v20; // [sp+18h] [bp-58h]
  int v21; // [sp+1Ch] [bp-54h] BYREF
  int v22; // [sp+20h] [bp-50h]
  int v23[4]; // [sp+28h] [bp-48h] BYREF
  __int16 v24; // [sp+38h] [bp-38h]
  int v25; // [sp+3Ah] [bp-36h]
  int v26[12]; // [sp+40h] [bp-30h] BYREF

  v19 = a2;
  v20 = a4;
  v22 = a3;
  v6 = *(_DWORD *)(a6 + 132);
  v7 = EtwpActiveSystemLoggers;
  v8 = 0;
  v9 = __clz(__rbit(EtwpActiveSystemLoggers));
  v17 = v6;
  v18 = result;
  if ( 1 != (unsigned __int8)(v9 >> 5) )
  {
    do
    {
      v7 &= v7 - 1;
      if ( &EtwpGroupMasks[8 * v9] )
      {
        if ( (EtwpGroupMasks[8 * v9 + 4] & 0x40) != 0 )
        {
          v10 = EtwpObjectTypeFilter[10 * v9];
          v11 = 0;
          if ( EtwpObjectTypeFilter[10 * v9] )
          {
            v16 = v6;
            v12 = &EtwpObjectTypeFilter[10 * v9];
            do
            {
              v13 = *((_DWORD *)v12 + 1);
              v12 += 2;
              result = 0;
              v14 = 0;
              v21 = v13;
              while ( 1 )
              {
                v15 = *((unsigned __int8 *)&v21 + v14);
                if ( v15 == 42 )
                {
LABEL_13:
                  v8 |= 1 << v9;
                  goto LABEL_14;
                }
                if ( v15 != 63
                  && (result != 3 || (*((_BYTE *)&v16 + v14) & 0x7F) != v15)
                  && *((unsigned __int8 *)&v16 + v14) != v15 )
                {
                  break;
                }
                ++result;
                ++v14;
                if ( result >= 4 )
                  goto LABEL_13;
              }
              ++v11;
            }
            while ( v11 < v10 );
LABEL_14:
            v6 = v17;
          }
        }
      }
      v9 = __clz(__rbit(v7));
    }
    while ( 1 != (unsigned __int8)(v9 >> 5) );
    if ( v8 )
    {
      v23[0] = v22;
      v23[1] = v18;
      v23[2] = v19;
      v25 = v20;
      v23[3] = a5;
      v24 = *(unsigned __int8 *)(a6 + 20);
      v26[0] = (int)v23;
      v26[1] = 0;
      v26[2] = 22;
      v26[3] = 0;
      result = EtwpTraceKernelEventWithFilter((int)v26, 1, v8, 4386, 273684739);
    }
  }
  return result;
}
