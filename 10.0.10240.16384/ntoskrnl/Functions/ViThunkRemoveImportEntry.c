// ViThunkRemoveImportEntry 
 
_DWORD *__fastcall ViThunkRemoveImportEntry(_DWORD *result, int a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r4
  __int64 v5; // kr00_8

  v2 = result;
  v3 = (_DWORD *)*result;
  while ( v3 != v2 )
  {
    result = v3;
    if ( v3[2] == a2 )
    {
      v5 = *(_QWORD *)v3;
      if ( *(_DWORD **)(*v3 + 4) != v3 || *(_DWORD **)HIDWORD(v5) != v3 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v5) = v5;
      *(_DWORD *)(v5 + 4) = HIDWORD(v5);
      v3 = (_DWORD *)*v3;
      result = (_DWORD *)ExFreePoolWithTag((unsigned int)result);
      --ViActiveVerifierThunks;
    }
    else
    {
      v3 = (_DWORD *)*v3;
    }
  }
  return result;
}
