// sub_525D3C 
 
void sub_525D3C()
{
  int v0; // r4
  int v1; // r5
  int v2; // r0
  int v3; // r1

  if ( v0 )
  {
    v1 = *(_DWORD *)(*(_DWORD *)(v0 + 12) + 60);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 68) )
      {
        v2 = IoGetOplockKeyContextEx(v0);
        if ( v2 )
        {
          if ( (*(_WORD *)(v2 + 2) & 1) != 0 )
          {
            v3 = *(_DWORD *)(v1 + 68);
            if ( *(_DWORD *)(v2 + 4) == *(_DWORD *)v3
              && *(unsigned __int16 *)(v2 + 8) == *(unsigned __int16 *)(v3 + 4)
              && *(unsigned __int16 *)(v2 + 10) == *(unsigned __int16 *)(v3 + 6)
              && *(unsigned __int8 *)(v2 + 12) == *(unsigned __int8 *)(v3 + 8)
              && *(unsigned __int8 *)(v2 + 13) == *(unsigned __int8 *)(v3 + 9)
              && *(unsigned __int8 *)(v2 + 14) == *(unsigned __int8 *)(v3 + 10)
              && *(unsigned __int8 *)(v2 + 15) == *(unsigned __int8 *)(v3 + 11)
              && *(unsigned __int8 *)(v2 + 16) == *(unsigned __int8 *)(v3 + 12)
              && *(unsigned __int8 *)(v2 + 17) == *(unsigned __int8 *)(v3 + 13)
              && *(unsigned __int8 *)(v2 + 18) == *(unsigned __int8 *)(v3 + 14)
              && *(unsigned __int8 *)(v2 + 19) == *(unsigned __int8 *)(v3 + 15) )
            {
              JUMPOUT(0x4606F2);
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x4606F8);
}
