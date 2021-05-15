// sub_96FAC0 
 
int sub_96FAC0()
{
  int v1; // r6
  unsigned __int16 *v2; // r7
  int *v3; // r8
  int v4; // r4
  unsigned __int16 v5; // r5
  int v6; // r0
  int v7; // r4
  __int16 *v8; // r5
  unsigned int v9; // r2
  int *v10; // r1
  int v11; // r0
  __int16 *v12; // r7
  int v13; // lr
  int v14; // r3
  int (*v15)(void); // [sp-4h] [bp-4h]

  v4 = (unsigned __int16)(2 * wcslen(v2));
  v5 = v4 + 2;
  v6 = ExAllocatePoolWithTag(512, v4 + 2, 1951556175);
  *(_DWORD *)(v1 + 4) = v6;
  if ( v6 )
  {
    *(_WORD *)v1 = v4;
    *(_WORD *)(v1 + 2) = v5;
    memmove(v6, (int)v2, v5);
    v7 = 32;
    v8 = (__int16 *)ObpTracePoolTagsBuffer;
    if ( ObpTracePoolTagsBuffer[0] )
    {
      v9 = (wcslen(ObpTracePoolTagsBuffer) + 1) / 5;
      if ( v9 > 0x10 )
        v9 = 16;
      if ( v9 )
      {
        v10 = v3;
        do
        {
          v11 = *v10;
          v12 = v8;
          v13 = 4;
          do
          {
            v14 = (unsigned __int16)v12[3];
            --v12;
            --v13;
            v11 = v14 | (v11 << 8);
          }
          while ( v13 );
          v8 += 5;
          --v9;
          *v10++ = v11;
        }
        while ( v9 );
      }
      v7 = 48;
    }
    if ( ObpTracePermanent )
      v7 |= 0x40u;
    if ( ObpInitStackAndObjectTables() < 0 )
    {
      if ( (v7 & 0x10) != 0 )
        memset(v3, 0, 64);
      if ( (v7 & 0x20) != 0 )
      {
        ExFreePoolWithTag(*(_DWORD *)(v1 + 4));
        RtlInitUnicodeStringEx(v1, 0);
      }
    }
    else
    {
      ObpRegTraceFlags = v7 | 1;
      ObpTraceFlags = v7 | 1;
      if ( ((v7 | 1) & 0x10) != 0 )
        ObpTracePoolTags = (int)v3;
      if ( (((unsigned __int8)v7 | 1) & 0x20) != 0 )
        ObpTraceProcessName = v1;
    }
  }
  return v15();
}
