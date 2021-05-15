// KdpGetContextEx 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KdpGetContextEx(_DWORD *a1, _WORD *a2, int a3, int a4)
{
  unsigned int v5; // r4 OVERLAPPED
  unsigned int v6; // r5
  unsigned int v8; // r3
  unsigned int v9; // r3
  int v11; // r3
  int v12; // r2
  int v13; // [sp+0h] [bp-18h] BYREF
  _DWORD *v14; // [sp+4h] [bp-14h]

  v13 = a3;
  v14 = (_DWORD *)a4;
  v5 = a1[5];
  v6 = a1[4];
  LOWORD(v13) = 56;
  v14 = a1;
  KdpGetContext(a1, a2);
  a1[6] = 0;
  if ( !a1[2] )
  {
    v8 = (unsigned __int16)*a2;
    if ( v6 >= v8 )
      v6 = (unsigned __int16)*a2;
    v9 = v8 - v6;
    if ( v5 > v9 )
      v5 = v9;
    if ( v6 )
      return sub_5546FC();
    a1[4] = 0;
    v11 = (unsigned __int16)*a2;
    *(_QWORD *)(a1 + 5) = *(_QWORD *)(&v5 - 1);
    v12 = (unsigned __int16)*a2;
    if ( v5 == v12 || v5 && v5 == v12 )
      KdpContextSent = 1;
    *a2 = v5;
  }
  return KdSendPacket_0(2, &v13, a2, &KdpContext);
}
