// MiDeliverPicoExceptionForProbedPage 
 
int __fastcall MiDeliverPicoExceptionForProbedPage(int a1, int a2)
{
  int v4; // r6
  int v6[24]; // [sp+8h] [bp-60h] BYREF

  memset(v6, 0, 80);
  v4 = -1073741819;
  v6[4] = 2;
  v6[0] = -1073741819;
  v6[6] = a1;
  if ( a2 )
    v6[5] = 1;
  if ( dword_61D9D0(v6, 0, 0, 0, 0) )
    v4 = 0;
  return v4;
}
