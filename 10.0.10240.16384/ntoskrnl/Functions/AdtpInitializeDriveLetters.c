// AdtpInitializeDriveLetters 
 
int AdtpInitializeDriveLetters()
{
  unsigned int v0; // r7
  int v1; // r9
  int v2; // r8
  __int16 *v3; // r6
  int v4; // r5
  int v5; // r4
  unsigned int v6; // r5
  __int16 *v7; // r4
  int v8; // r6
  int v9; // r3
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // [sp+4h] [bp-88h] BYREF
  int v15; // [sp+8h] [bp-84h]
  int v16; // [sp+Ch] [bp-80h] BYREF
  int v17; // [sp+10h] [bp-7Ch]
  char *v18; // [sp+14h] [bp-78h]
  int v19; // [sp+18h] [bp-74h]
  int v20; // [sp+1Ch] [bp-70h]
  int v21; // [sp+20h] [bp-6Ch]
  char v22[4]; // [sp+24h] [bp-68h] BYREF
  int v23; // [sp+28h] [bp-64h]
  unsigned __int16 v24[48]; // [sp+2Ch] [bp-60h] BYREF

  v14 = 0;
  v0 = 0;
  sub_463468((char *)v24);
  RtlInitUnicodeString((unsigned int)v22, v24);
  v1 = v23;
  v2 = 0;
  v15 = v23;
  v3 = &DriveMappingArray;
  while ( 1 )
  {
    *(_WORD *)(v1 + 24) = v2 + 65;
    v16 = 24;
    v17 = 0;
    v18 = v22;
    v19 = 576;
    v20 = 0;
    v21 = 0;
    v4 = NtOpenSymbolicLinkObject((unsigned int)&v14, 1, (int)&v16, v2 + 65);
    v5 = -1073741801;
    if ( v4 >= 0 )
      break;
LABEL_3:
    if ( (unsigned int)++v2 >= 0x1A )
      goto LABEL_4;
  }
  *v3 = *(_WORD *)(v1 + 24);
  v11 = ExAllocatePoolWithTag(1, 256, 1799447891);
  if ( v11 )
  {
    *((_DWORD *)v3 + 2) = v11;
    v12 = v14;
    v3[2] = 0;
    v3[3] = 256;
    v4 = NtQuerySymbolicLinkObject(v12, (unsigned int)(v3 + 2), 0, 0);
    v13 = NtClose();
    if ( v4 < 0 )
      return sub_8104E0(v13);
    ++v0;
    v3 += 6;
    v1 = v15;
    goto LABEL_3;
  }
  v4 = -1073741801;
LABEL_4:
  if ( v4 != -1073741801 )
  {
    v6 = 0;
    if ( v0 )
    {
      v7 = &word_9277A4;
      do
      {
        v20 = 0;
        v21 = 0;
        v8 = 0;
        v16 = 24;
        v17 = 0;
        v18 = (char *)v7;
        v19 = 576;
        if ( NtOpenSymbolicLinkObject((unsigned int)&v14, 1, (int)&v16, 0) >= 0 )
        {
          if ( NtQuerySymbolicLinkObject(v14, (unsigned int)v7, 0, v9) < 0 )
          {
            ExFreePoolWithTag(*((_DWORD *)v7 + 1));
            RtlInitUnicodeString((unsigned int)v7, 0);
          }
          else
          {
            v8 = 1;
          }
          NtClose();
          if ( v8 )
            continue;
        }
        ++v6;
        v7 += 6;
      }
      while ( v6 < v0 );
    }
    v5 = 0;
  }
  return v5;
}
