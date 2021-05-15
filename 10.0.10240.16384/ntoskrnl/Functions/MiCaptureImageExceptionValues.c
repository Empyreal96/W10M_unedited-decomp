// MiCaptureImageExceptionValues 
 
_BYTE *__fastcall MiCaptureImageExceptionValues(_DWORD *a1)
{
  int v2; // r7
  int v3; // r0
  _DWORD *v4; // r5
  _DWORD *v5; // r8
  _BYTE *result; // r0
  int v7; // r1
  int v8; // r2

  v2 = a1[6];
  v3 = RtlImageNtHeader(v2);
  v4 = (_DWORD *)a1[34];
  v5 = (_DWORD *)v3;
  *v4 = a1[8] >> 12;
  v4[1] = v4 + 2;
  result = RtlClearAllBits((int)v4);
  if ( v5[29] > 3u )
  {
    v7 = a1[21];
    a1[2] = v5[36] + v2;
    v8 = a1[2];
    a1[3] = v5[37];
    result = (_BYTE *)RtlMarkExceptionHandlingPages(v2, v7, v8);
    if ( (int)result < 0 )
      result = (_BYTE *)sub_7CDD9C();
  }
  return result;
}
