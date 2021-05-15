// BiCreatePartitionDevice 
 
int __fastcall BiCreatePartitionDevice(unsigned __int16 *a1, char a2, int *a3, int a4)
{
  _DWORD *v7; // r6
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r4
  unsigned int v12; // r5
  int v13; // r1
  _BYTE *v14; // r0
  int v15; // r8
  int v16; // r2
  _DWORD *v17; // r2
  int v18[2]; // [sp+Ch] [bp-144h] BYREF
  int v19; // [sp+14h] [bp-13Ch]
  int v20; // [sp+18h] [bp-138h]
  int v21; // [sp+1Ch] [bp-134h]
  int v22; // [sp+20h] [bp-130h]
  _DWORD *v23; // [sp+24h] [bp-12Ch]
  int *v24; // [sp+28h] [bp-128h]
  int v25; // [sp+30h] [bp-120h]
  int v26; // [sp+34h] [bp-11Ch]
  char *v27; // [sp+38h] [bp-118h]
  int v28; // [sp+3Ch] [bp-114h]
  int v29; // [sp+40h] [bp-110h]
  int v30; // [sp+44h] [bp-10Ch]
  char v31[8]; // [sp+48h] [bp-108h] BYREF
  int v32[36]; // [sp+58h] [bp-F8h] BYREF
  int v33[26]; // [sp+E8h] [bp-68h] BYREF

  v23 = (_DWORD *)a4;
  v24 = a3;
  v18[0] = 0;
  v20 = 0;
  v21 = 0;
  v18[1] = 0;
  v19 = 0;
  v22 = 0;
  memset(v33, 0, 72);
  if ( BiGetDriveLayoutInformation(a1, v18) < 0 )
    return sub_81329C();
  v7 = (_DWORD *)v18[0];
  if ( (a2 & 0x40) == 0 && BiGetPartitionVhdFilePath(a1) )
    JUMPOUT(0x8132CC);
  v33[8] = 0;
  if ( !*v7 )
    JUMPOUT(0x813336);
  if ( *v7 != 1 )
    goto LABEL_31;
  v33[9] = 0;
  v8 = v7[3];
  v9 = v7[4];
  v10 = v7[5];
  v33[10] = v7[2];
  v33[11] = v8;
  v33[12] = v9;
  v33[13] = v10;
  RtlInitUnicodeString((unsigned int)v31, a1);
  v25 = 24;
  v26 = 0;
  v28 = 576;
  v27 = v31;
  v29 = 0;
  v30 = 0;
  v11 = ZwOpenFile();
  if ( v11 >= 0 )
  {
    v11 = BiGetPartitionInformation(v21, *v7, v32);
    if ( v11 >= 0 )
    {
      if ( !v32[0] )
        JUMPOUT(0x813342);
      if ( v32[0] == 1 )
      {
        v33[4] = v32[12];
        v33[5] = v32[13];
        v33[6] = v32[14];
        v33[7] = v32[15];
        v12 = v19 + 56;
        if ( (unsigned int)(v19 + 56) > 0x48 )
          v13 = v19 + 56;
        else
          v13 = 72;
        v14 = (_BYTE *)ExAllocatePoolWithTag(1, v13, 1262764866);
        v15 = (int)v14;
        if ( v14 )
        {
          if ( v12 > 0x48 )
            v16 = v12;
          else
            v16 = 72;
          memset(v14, 0, v16);
          v33[0] = 6;
          if ( v12 > 0x48 )
            v33[2] = v12;
          else
            v33[2] = 72;
          memmove(v15, (int)v33, 0x48u);
          v17 = v23;
          *v24 = v15;
          *v17 = v7[1];
        }
        else
        {
          v11 = -1073741670;
        }
        goto LABEL_19;
      }
LABEL_31:
      JUMPOUT(0x81335E);
    }
  }
LABEL_19:
  if ( v21 )
    ZwClose();
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  return v11;
}
