// IoConnectInterruptEx 
 
int __fastcall IoConnectInterruptEx(int *a1)
{
  int v2; // r2
  int v3; // r5
  int v4; // r7
  unsigned int v5; // r6
  unsigned int v6; // r0
  unsigned int v7; // r5
  _DWORD *v8; // r1
  int v9; // r5
  int v11; // r0
  __int64 v13; // r1
  int v14; // r0
  int v15; // r3
  unsigned int *v16; // [sp+20h] [bp-80h] BYREF
  int v17; // [sp+28h] [bp-78h] BYREF
  int v18; // [sp+2Ch] [bp-74h]
  int v19; // [sp+30h] [bp-70h]
  int v20[26]; // [sp+38h] [bp-68h] BYREF

  if ( KeGetCurrentIrql(a1) )
    sub_7DEE60();
  v2 = *a1;
  if ( *a1 == 4 || v2 == 1 )
  {
    if ( a1[1] && a1[3] && *((unsigned __int8 *)a1 + 24) >= (unsigned int)*((unsigned __int8 *)a1 + 32) )
    {
      if ( *((_BYTE *)a1 + 24) || *((_BYTE *)a1 + 32) )
      {
        v3 = 0;
        goto LABEL_10;
      }
      v3 = 1;
      if ( !a1[5] )
      {
LABEL_10:
        if ( v2 == 4 )
          v4 = *((unsigned __int16 *)a1 + 22);
        else
          v4 = 0;
        if ( IopGetInterruptConnectionData() >= 0 )
        {
          memset(v20, 0, 80);
          v5 = (unsigned int)v16;
          v6 = 0;
          v7 = *v16;
          v20[0] = 0;
          if ( !v7 )
          {
LABEL_46:
            ExFreePoolWithTag((unsigned int)v16);
            goto LABEL_38;
          }
          v8 = v16 + 2;
          while ( v8[1] != a1[7]
               || *((_BYTE *)a1 + 32) && *((unsigned __int8 *)v8 + 8) != *((unsigned __int8 *)a1 + 32)
               || v8[4] != a1[9]
               || *((unsigned __int16 *)v8 + 12) != v4
               || v8[5] != a1[10] )
          {
            ++v6;
            v8 += 18;
            if ( v6 >= v7 )
              goto LABEL_46;
          }
          v20[0] = 1;
          memmove((int)&v20[2], (int)&v16[18 * v6 + 2], 0x48u);
          if ( !v20[2] && (v20[15] & 1) != 0 )
            *((_BYTE *)a1 + 26) = 1;
          v9 = IopConnectInterrupt(
                 &v16,
                 a1[3],
                 0,
                 a1[4],
                 0,
                 a1[5],
                 *((unsigned __int8 *)a1 + 24),
                 *((unsigned __int8 *)a1 + 26));
          if ( v9 >= 0 )
            *(_DWORD *)a1[2] = v16 + 22;
          ExFreePoolWithTag(v5);
          return v9;
        }
        if ( v3 )
          goto LABEL_38;
        v17 = 0;
        v18 = 0;
        v19 = 0;
        v13 = *(_QWORD *)(a1 + 3);
        v14 = a1[2];
        v17 = a1[10];
        v15 = *((unsigned __int8 *)a1 + 26);
        LOWORD(v18) = v4;
        return IopConnectInterruptFullySpecified(
                 v14,
                 v13,
                 HIDWORD(v13),
                 a1[5],
                 a1[7],
                 *((unsigned __int8 *)a1 + 32),
                 *((unsigned __int8 *)a1 + 24),
                 a1[9],
                 v15,
                 &v17);
      }
    }
    return -1073741811;
  }
  if ( v2 != 3 )
  {
    if ( v2 != 2 )
    {
      *a1 = 3;
      goto LABEL_38;
    }
    return IopConnectLineBasedInterrupt(a1[1], a1[2], a1[3], a1[4], a1[5], *((unsigned __int8 *)a1 + 24));
  }
  v9 = IopConnectMessageBasedInterrupt(a1[1], a1[2], a1[3], a1[4], a1[5], *((unsigned __int8 *)a1 + 24));
  if ( v9 < 0 )
  {
    if ( a1[7] )
    {
      v11 = IopConnectLineBasedInterrupt(a1[1], a1[2], a1[7], a1[4], a1[5], *((unsigned __int8 *)a1 + 24));
      *a1 = 2;
      return v11;
    }
LABEL_38:
    v9 = -1073741637;
  }
  return v9;
}
