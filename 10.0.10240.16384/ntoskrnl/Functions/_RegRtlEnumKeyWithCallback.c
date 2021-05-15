// _RegRtlEnumKeyWithCallback 
 
int __fastcall RegRtlEnumKeyWithCallback(int a1, int a2, int a3)
{
  int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r1
  unsigned int v8; // r3
  unsigned int v9; // r6
  char *v10; // r7
  int v11; // r9
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  unsigned int v16; // [sp+8h] [bp-88h] BYREF
  unsigned int v17; // [sp+Ch] [bp-84h] BYREF
  unsigned int v18; // [sp+10h] [bp-80h] BYREF
  int v19; // [sp+14h] [bp-7Ch]
  int v20; // [sp+18h] [bp-78h]
  char v21; // [sp+20h] [bp-70h] BYREF

  v18 = 0;
  v19 = a1;
  v20 = a3;
  v4 = 0;
  v5 = 0;
  if ( RtlpGetStackLimits((int)&v17, (int)&v16, a3, 0) )
    v6 = v17;
  else
    v6 = 0;
  if ( (unsigned int)&v16 - v6 < 0x400 )
    return sub_811BD0();
  if ( RegRtlQueryInfoKey(a1, 0, &v16, 0, 0, 0) )
  {
    v9 = 0;
    goto LABEL_11;
  }
  v8 = v16;
  if ( v16 )
  {
    if ( v16 + 1 < v16 )
      return -1073741675;
    v8 = v16 + 1;
  }
  v4 = RtlULongLongToULong(2 * v8, (unsigned __int64)v8 >> 31, &v16);
  if ( v4 >= 0 )
  {
    v9 = v16;
LABEL_11:
    if ( v9 <= 0x50 )
    {
      v10 = &v21;
      v9 = 80;
      goto LABEL_13;
    }
    v18 = v9;
    v14 = ExAllocatePoolWithTag(1, v9, 1279739218);
    v5 = v14;
    if ( v14 )
    {
      v10 = (char *)v14;
LABEL_13:
      v11 = 0;
      while ( 1 )
      {
        v17 = v9 >> 1;
        v12 = RegRtlEnumKey(v19, v11, (int)v10, &v17);
        if ( v12 == -2147483622 || v12 == -1073741444 )
          break;
        if ( v12 == -1073741789 )
        {
          v4 = RtlULongLongToULong(2 * v17, (unsigned __int64)v17 >> 31, &v18);
          if ( v4 < 0 )
            break;
          if ( v5 )
            ExFreePoolWithTag(v5);
          v9 = v18;
          v15 = ExAllocatePoolWithTag(1, v18, 1279739218);
          v5 = v15;
          if ( !v15 )
            goto LABEL_32;
          v10 = (char *)v15;
        }
        else
        {
          if ( v12 )
          {
            v4 = v12;
            break;
          }
          *(_WORD *)&v10[2 * (v9 >> 1) - 2] = 0;
          if ( SysCtxInternalEnumSubkeyCallback )
            v13 = SysCtxInternalEnumSubkeyCallback(v19, (int)v10, v20);
          else
            v13 = 0;
          if ( v13 )
          {
            if ( v13 == 1 )
            {
              v11 = 0;
            }
            else if ( v13 != 2 )
            {
              if ( v13 == 3 )
                v4 = -1073741248;
              else
                v4 = -1073741595;
              break;
            }
          }
          else
          {
            ++v11;
          }
          if ( v4 || v13 == 2 )
            break;
        }
      }
      if ( v5 )
        ExFreePoolWithTag(v5);
      return v4;
    }
LABEL_32:
    v4 = -1073741801;
  }
  return v4;
}
