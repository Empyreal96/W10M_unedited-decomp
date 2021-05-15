// SmKmFileInfoDuplicate 
 
int __fastcall SmKmFileInfoDuplicate(_DWORD *a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  _DWORD *v11; // r6
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v16; // [sp+10h] [bp-38h] BYREF
  int v17; // [sp+14h] [bp-34h] BYREF
  int v18[12]; // [sp+18h] [bp-30h] BYREF

  v16 = 0;
  memset(v18, 0, 32);
  v4 = ObOpenObjectByPointer(SmKmGlobals, 512, 0, 0, 0, 0, &v16);
  if ( v4 >= 0 )
  {
    if ( !*a2
      || (v4 = ZwDuplicateObject(), v4 >= 0)
      && (v4 = ObReferenceObjectByHandle(v18[0], 65539, 0, 0, (int)&v17, 0), v18[1] = v17, v4 >= 0) )
    {
      v5 = a2[2];
      if ( v5 )
      {
        v18[2] = a2[2];
        ObfReferenceObject(v5);
        v18[3] = a2[3];
      }
      v6 = a2[7];
      v7 = SmAlloc(16 * v6, 1951952243);
      v18[6] = v7;
      if ( v7 )
      {
        memmove(v7, a2[6], 16 * v6);
        v18[7] = a2[7];
        v8 = v18[1];
        v9 = v18[2];
        v10 = v18[3];
        *a1 = v18[0];
        a1[1] = v8;
        a1[2] = v9;
        a1[3] = v10;
        v11 = a1 + 4;
        v12 = v18[5];
        v13 = v18[6];
        v14 = v18[7];
        *v11 = v18[4];
        v11[1] = v12;
        v11[2] = v13;
        v11[3] = v14;
        memset(v18, 0, 32);
        v4 = 0;
      }
      else
      {
        v4 = -1073741670;
      }
    }
  }
  if ( v16 )
    ZwClose();
  SmKmFileInfoCleanup(v18);
  return v4;
}
