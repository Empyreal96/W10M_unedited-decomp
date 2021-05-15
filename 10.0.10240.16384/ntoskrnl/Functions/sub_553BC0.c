// sub_553BC0 
 
void __fastcall sub_553BC0(int a1, int a2, __int64 *a3)
{
  _DWORD *v3; // r4
  __int64 v4; // kr00_8
  int v5; // r0

  v4 = *a3;
  if ( *((_DWORD **)a3 + 1) == v3 && *(__int64 **)(v4 + 4) == a3 )
  {
    *v3 = v4;
    *(_DWORD *)(v4 + 4) = v3;
    v5 = **((_DWORD **)a3 + 21);
    if ( v5 )
      KiSignalWaitDisconnectLock(v5, 0);
    JUMPOUT(0x4F498E);
  }
  __fastfail(3u);
}
