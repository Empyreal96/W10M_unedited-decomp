// sub_7CBC64 
 
// local variable allocation has failed, the output may be wrong!
void sub_7CBC64()
{
  int v0; // r7
  int v1; // lr
  _DWORD *v2; // r5
  int v3; // r1
  int v4; // r2
  int v5; // r3
  _DWORD *v6; // r2 OVERLAPPED
  int v7; // r1 OVERLAPPED

  v2 = *(_DWORD **)(v0 + 28);
  v3 = v2[1];
  v4 = v2[2];
  v5 = v2[3];
  *(_DWORD *)(v1 + 40) = *v2;
  *(_DWORD *)(v1 + 44) = v3;
  *(_DWORD *)(v1 + 48) = v4;
  *(_DWORD *)(v1 + 52) = v5;
  v6 = (_DWORD *)WmipGEHeadPtr;
  v7 = *(_DWORD *)WmipGEHeadPtr;
  *(_QWORD *)v1 = *(_QWORD *)&v7;
  if ( *(_DWORD **)(v7 + 4) == v6 )
  {
    *(_DWORD *)(v7 + 4) = v1;
    *v6 = v1;
    JUMPOUT(0x76EC80);
  }
  __fastfail(3u);
}
