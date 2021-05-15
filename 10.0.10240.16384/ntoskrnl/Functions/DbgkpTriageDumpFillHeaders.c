// DbgkpTriageDumpFillHeaders 
 
int __fastcall DbgkpTriageDumpFillHeaders(int *a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // r7
  unsigned int v8; // r2
  int result; // r0
  int v10; // r3
  int v11; // [sp+28h] [bp-20h] BYREF
  int v12[7]; // [sp+2Ch] [bp-1Ch] BYREF

  v7 = (_DWORD *)*a1;
  IoFillDumpHeader(*a1, 4, a2, a3, a4, a5, a6, 0);
  v8 = a1[1];
  v11 = 0;
  v12[0] = 0;
  if ( v8 < 0x1000 )
    return -1073741670;
  result = IoFillTriageDumpBuffer(v8 - 4096, (int)(v7 + 1024), 0, 1088, &v11, 0, 0, CmNtCSDVersion, 0, 0, 0, 0, v12);
  if ( result >= 0 )
  {
    v7[995] = v11;
    a1[5] = (v12[0] + 4103) & 0xFFFFFFF8;
    v10 = a1[1];
    v7[1049] = 0;
    v7[1048] = v10 - 4;
    result = 0;
  }
  return result;
}
