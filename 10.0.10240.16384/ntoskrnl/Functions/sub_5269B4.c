// sub_5269B4 
 
void __fastcall sub_5269B4(int a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  __int64 v3; // r2

  v3 = *(_QWORD *)a2;
  if ( (_DWORD *)a2[1] == v2 && *(_DWORD **)(v3 + 4) == a2 )
  {
    *v2 = v3;
    *(_DWORD *)(v3 + 4) = v2;
    ExFreeToNPagedLookasideList((int)&CcVacbLevelLookasideList, a2);
    --v2[3];
    JUMPOUT(0x461D52);
  }
  __fastfail(3u);
}
