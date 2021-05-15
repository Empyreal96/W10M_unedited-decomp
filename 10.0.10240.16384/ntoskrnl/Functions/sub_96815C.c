// sub_96815C 
 
void __fastcall sub_96815C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, unsigned __int16 a21, int a22)
{
  int v22; // r4
  int v23; // r5
  int v24; // r7
  int v25; // r10
  int v26; // r0
  int v27; // r0
  int v28; // r0

  if ( a22 )
    (*(void (__fastcall **)(int, _DWORD))(v22 + 16))(a22, a21);
  if ( v25 )
    (*(void (__fastcall **)(int, _DWORD))(v22 + 16))(v25, 0);
  if ( v24 )
  {
    v26 = *(_DWORD *)(v24 + 12);
    if ( v26 )
      (*(void (__fastcall **)(int, _DWORD))(v22 + 16))(v26, *(unsigned __int16 *)(v24 + 8));
    v27 = *(_DWORD *)(v24 + 20);
    if ( v27 )
      (*(void (__fastcall **)(int, _DWORD))(v22 + 16))(v27, *(unsigned __int16 *)(v24 + 16));
    v28 = *(_DWORD *)(v23 + 56);
    if ( v28 )
      (*(void (__fastcall **)(int, _DWORD))(v22 + 16))(v28, *(unsigned __int16 *)(v23 + 52));
    (*(void (__fastcall **)(int, int))(v22 + 16))(v23, 68);
  }
  JUMPOUT(0x94EFEA);
}
