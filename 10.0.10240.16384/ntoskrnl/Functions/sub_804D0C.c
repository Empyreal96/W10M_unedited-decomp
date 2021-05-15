// sub_804D0C 
 
void sub_804D0C()
{
  _DWORD *v0; // r4
  unsigned int v1; // r5
  __int64 v2; // r2

  v2 = *(_QWORD *)v1;
  if ( *(_DWORD **)(v1 + 4) == v0 && *(_DWORD *)(v2 + 4) == v1 )
  {
    *v0 = v2;
    *(_DWORD *)(v2 + 4) = v0;
    ObDereferenceObjectDeferDelete(*(_DWORD *)(v1 + 8));
    ExFreePoolWithTag(v1);
    JUMPOUT(0x74E016);
  }
  __fastfail(3u);
}
