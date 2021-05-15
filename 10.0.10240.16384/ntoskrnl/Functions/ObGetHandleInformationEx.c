// ObGetHandleInformationEx 
 
int __fastcall ObGetHandleInformationEx(_DWORD *a1, unsigned int a2, _DWORD *a3, int a4)
{
  int result; // r0
  int v6[4]; // [sp+8h] [bp-10h] BYREF

  v6[1] = a4;
  v6[0] = 8;
  if ( a2 < 8 )
    return -1073741820;
  *a1 = 0;
  result = ExpSnapShotHandleTables(ObpCaptureHandleInformationEx, a1, a2, v6, 1, a2);
  if ( a3 )
    *a3 = v6[0];
  return result;
}
