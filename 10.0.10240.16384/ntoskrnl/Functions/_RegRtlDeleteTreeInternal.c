// _RegRtlDeleteTreeInternal 
 
int __fastcall RegRtlDeleteTreeInternal(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v7; // r6
  unsigned int v8; // r4
  int v9; // r4
  unsigned int v11; // r5
  int v12; // r7
  int v13; // r0
  int v14; // [sp+0h] [bp-38h]
  int v15; // [sp+4h] [bp-34h]
  int v16; // [sp+8h] [bp-30h] BYREF
  unsigned int v17; // [sp+Ch] [bp-2Ch] BYREF
  unsigned int v18; // [sp+10h] [bp-28h] BYREF
  int v19; // [sp+14h] [bp-24h]
  int v20[8]; // [sp+18h] [bp-20h] BYREF

  v16 = 0;
  v17 = 0;
  v19 = a4;
  v7 = 0;
  if ( RtlpGetStackLimits((int)&v18, (int)v20, a3, 0) )
    v8 = v18;
  else
    v8 = 0;
  if ( (unsigned int)v20 - v8 < 0x400 )
  {
    v9 = -1073741670;
    goto LABEL_5;
  }
  v9 = RegRtlOpenKeyTransacted(a1, a2, 0, 196639, (int)&v16, a3);
  if ( v9 >= 0 )
  {
    v15 = 0;
    v14 = 0;
    if ( RegRtlQueryInfoKey(v16, 0, v20, 0) )
    {
      v11 = 0;
      v17 = 0;
    }
    else
    {
      if ( v20[0] )
        return sub_7EE7AC();
      v9 = RtlULongLongToULong(0, 0, &v17);
      if ( v9 < 0 )
        goto LABEL_5;
      v11 = v17;
    }
    if ( !v11 || (v7 = ExAllocatePoolWithTag(1, v11, 1279739218)) != 0 )
    {
LABEL_16:
      v12 = 0;
      while ( 1 )
      {
        v18 = v11 >> 1;
        v13 = RegRtlEnumKey(v16, v12++, v7, &v18, v14, v15);
        if ( v13 == -2147483622 || v13 == -1073741444 )
          break;
        if ( v13 == -1073741789 )
        {
          v9 = RtlULongLongToULong(2 * v18, (unsigned __int64)v18 >> 31, &v17);
          if ( v9 < 0 )
            goto LABEL_5;
          if ( v7 )
            ExFreePoolWithTag(v7);
          v11 = v17;
          v7 = ExAllocatePoolWithTag(1, v17, 1279739218);
          if ( !v7 )
          {
            v9 = -1073741801;
            break;
          }
          --v12;
        }
        else
        {
          if ( v13 )
            break;
          *(_WORD *)(v7 + 2 * (v11 >> 1) - 2) = 0;
          if ( !RegRtlDeleteTreeInternal(v16, v7, a3, v19) )
            goto LABEL_16;
        }
      }
      if ( v9 >= 0 )
        v9 = RegRtlDeleteKeyTransacted(a1, a2, a3, v19);
    }
    else
    {
      v9 = -1073741801;
    }
  }
LABEL_5:
  if ( v16 )
    ZwClose();
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v9;
}
