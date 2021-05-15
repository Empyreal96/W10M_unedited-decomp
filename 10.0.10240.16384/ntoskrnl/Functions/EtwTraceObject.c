// EtwTraceObject 
 
int __fastcall EtwTraceObject(int result, int a2)
{
  int v2; // r5
  char v3; // r2
  int v4; // r2
  unsigned int v5; // r7
  unsigned int v6; // r4
  unsigned int v7; // lr
  unsigned int v8; // r6
  unsigned __int16 *v9; // r8
  int v10; // t1
  unsigned int v11; // r1
  int v12; // r2
  int v13; // [sp+8h] [bp-50h] BYREF
  int v14; // [sp+Ch] [bp-4Ch]
  int v15; // [sp+10h] [bp-48h]
  int v16; // [sp+14h] [bp-44h]
  int v17; // [sp+18h] [bp-40h] BYREF
  int v18; // [sp+1Ch] [bp-3Ch]
  int v19; // [sp+20h] [bp-38h] BYREF
  __int16 v20; // [sp+24h] [bp-34h]
  int v21[12]; // [sp+28h] [bp-30h] BYREF

  v2 = 0;
  v3 = *(_BYTE *)(a2 + 12) ^ BYTE1(a2);
  v15 = a2;
  v16 = result;
  v18 = (unsigned __int8)(ObHeaderCookie ^ v3);
  v4 = *(_DWORD *)(ObTypeIndexTable[v18] + 132);
  v14 = v4;
  v5 = EtwpActiveSystemLoggers;
  v6 = __clz(__rbit(EtwpActiveSystemLoggers));
  if ( 1 != (unsigned __int8)(v6 >> 5) )
  {
    do
    {
      v5 &= v5 - 1;
      if ( &EtwpGroupMasks[8 * v6] )
      {
        if ( (EtwpGroupMasks[8 * v6 + 4] & 0x80) != 0 )
        {
          v7 = EtwpObjectTypeFilter[10 * v6];
          v8 = 0;
          if ( EtwpObjectTypeFilter[10 * v6] )
          {
            v13 = v4;
            v9 = &EtwpObjectTypeFilter[10 * v6];
            do
            {
              v10 = *((_DWORD *)v9 + 1);
              v9 += 2;
              v11 = 0;
              v12 = 0;
              v17 = v10;
              while ( 1 )
              {
                result = *((unsigned __int8 *)&v17 + v12);
                if ( result == 42 )
                {
LABEL_13:
                  v2 |= 1 << v6;
                  goto LABEL_14;
                }
                if ( result != 63
                  && (v11 != 3 || (*((_BYTE *)&v13 + v12) & 0x7F) != result)
                  && *((unsigned __int8 *)&v13 + v12) != result )
                {
                  break;
                }
                ++v11;
                ++v12;
                if ( v11 >= 4 )
                  goto LABEL_13;
              }
              ++v8;
            }
            while ( v8 < v7 );
LABEL_14:
            v4 = v14;
          }
        }
      }
      v6 = __clz(__rbit(v5));
    }
    while ( 1 != (unsigned __int8)(v6 >> 5) );
    if ( v2 )
    {
      v19 = v15 + 24;
      v20 = v18;
      v21[0] = (int)&v19;
      v21[1] = 0;
      v21[2] = 8;
      v21[3] = 0;
      result = EtwpTraceKernelEventWithFilter((int)v21, 1, v2, v16, 273684738);
    }
  }
  return result;
}
