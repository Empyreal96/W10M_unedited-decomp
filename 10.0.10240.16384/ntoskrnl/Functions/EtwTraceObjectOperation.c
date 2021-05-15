// EtwTraceObjectOperation 
 
unsigned int __fastcall EtwTraceObjectOperation(unsigned int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r2
  unsigned int v7; // r7
  unsigned int v8; // r4
  unsigned int v9; // r8
  unsigned int v10; // r6
  char *v11; // lr
  int v12; // t1
  int v13; // r2
  int v14; // r1
  int v15; // [sp+8h] [bp-60h] BYREF
  int v16; // [sp+Ch] [bp-5Ch]
  int v17; // [sp+10h] [bp-58h]
  int v18; // [sp+14h] [bp-54h]
  unsigned int v19; // [sp+18h] [bp-50h]
  int v20; // [sp+1Ch] [bp-4Ch] BYREF
  int v21; // [sp+20h] [bp-48h]
  int v22[4]; // [sp+28h] [bp-40h] BYREF
  int v23[12]; // [sp+38h] [bp-30h] BYREF

  v17 = a4;
  v18 = a3;
  v4 = *(unsigned __int8 *)(a2 + 12);
  v21 = a2;
  v19 = result;
  v5 = 0;
  v6 = *(_DWORD *)(ObTypeIndexTable[v4 ^ BYTE1(a2) ^ (unsigned __int8)ObHeaderCookie] + 132);
  v16 = v6;
  v7 = EtwpActiveSystemLoggers;
  v8 = __clz(__rbit(EtwpActiveSystemLoggers));
  if ( 1 != (unsigned __int8)(v8 >> 5) )
  {
    do
    {
      v7 &= v7 - 1;
      if ( &EtwpGroupMasks[8 * v8] )
      {
        if ( (EtwpGroupMasks[8 * v8 + 4] & 0x80) != 0 )
        {
          v9 = EtwpObjectTypeFilter[10 * v8];
          v10 = 0;
          if ( EtwpObjectTypeFilter[10 * v8] )
          {
            v15 = v6;
            v11 = (char *)&EtwpObjectTypeFilter[10 * v8];
            do
            {
              v12 = *((_DWORD *)v11 + 1);
              v11 += 4;
              result = 0;
              v13 = 0;
              v20 = v12;
              while ( 1 )
              {
                v14 = *((unsigned __int8 *)&v20 + v13);
                if ( v14 == 42 )
                {
LABEL_13:
                  v5 |= 1 << v8;
                  goto LABEL_14;
                }
                if ( v14 != 63
                  && (result != 3 || (*((_BYTE *)&v15 + v13) & 0x7F) != v14)
                  && *((unsigned __int8 *)&v15 + v13) != v14 )
                {
                  break;
                }
                ++result;
                ++v13;
                if ( result >= 4 )
                  goto LABEL_13;
              }
              ++v10;
            }
            while ( v10 < v9 );
LABEL_14:
            v6 = v16;
          }
        }
      }
      v8 = __clz(__rbit(v7));
    }
    while ( 1 != (unsigned __int8)(v8 >> 5) );
    if ( v5 )
    {
      v22[0] = v21 + 24;
      v22[1] = v17;
      v22[2] = v18;
      v23[0] = (int)v22;
      v23[1] = 0;
      v23[2] = 12;
      v23[3] = 0;
      result = EtwpTraceKernelEventWithFilter(v23, 1, v5, v19, 290463490);
    }
  }
  return result;
}
