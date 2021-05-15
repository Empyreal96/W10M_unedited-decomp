// RtlVirtualUnwind 
 
int __fastcall RtlVirtualUnwind(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, int a8)
{
  int v9[4]; // [sp+20h] [bp-10h] BYREF

  v9[0] = 0;
  if ( RtlpxVirtualUnwind((int)a6, a2, a3, a4, a5, a6, a7, a8, 0, 0, v9) < 0 )
    a5[16] = 0;
  return v9[0];
}
