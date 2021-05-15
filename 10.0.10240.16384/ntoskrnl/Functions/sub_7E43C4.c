// sub_7E43C4 
 
void sub_7E43C4()
{
  unsigned int v0; // r0
  int v1; // r2
  int v2; // r4
  unsigned int v3; // r5
  __int64 **v4; // r2
  __int64 *v5; // r6
  __int64 v6; // kr00_8

  v3 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v4 = (__int64 **)(v3 + *(_DWORD *)(v2 + 12));
      if ( *v4 == (__int64 *)v4 )
        break;
      v5 = *v4;
      v6 = **v4;
      if ( (__int64 **)HIDWORD(v6) != v4 || *(__int64 **)(v6 + 4) != v5 )
        __fastfail(3u);
      *v4 = (__int64 *)v6;
      *(_DWORD *)(v6 + 4) = v4;
      RtlFreeAnsiString((_DWORD *)v5 + 2);
      v0 = *((_DWORD *)v5 + 6);
      if ( v0 )
      {
        v1 = *((_DWORD *)v5 + 4);
        if ( (unsigned __int16)v1 == 0x8000 )
        {
          if ( (v1 & 0x100000) != 0 )
            PnpCtxRegDeleteTree((int *)PiPnpRtlCtx, *((_DWORD *)v5 + 6), 0);
          ZwClose();
        }
        else
        {
          ExFreePoolWithTag(v0);
        }
      }
      ExFreePoolWithTag((unsigned int)v5);
    }
    v3 += 8;
    if ( v3 >= 0x3F8 )
    {
      ExFreePoolWithTag(*(_DWORD *)(v2 + 12));
      JUMPOUT(0x77CC06);
    }
  }
}
