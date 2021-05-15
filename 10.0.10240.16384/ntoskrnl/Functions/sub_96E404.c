// sub_96E404 
 
void sub_96E404(int a1, int a2, int a3, int a4, ...)
{
  int *v4; // r5
  va_list va; // [sp+0h] [bp+0h]
  int v6; // [sp+0h] [bp+0h] BYREF
  int v7; // [sp+4h] [bp+4h]
  va_list va1; // [sp+8h] [bp+8h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v6 = va_arg(va1, _DWORD);
  v7 = va_arg(va1, _DWORD);
  *(_DWORD *)(*v4 + 8) = 18;
  if ( RtlValidSid((_BYTE *)*v4) )
  {
    if ( PiAuAllocateAndInitializeSid(v4 + 1, (int)va1, 1u) >= 0 )
    {
      *(_DWORD *)(v4[1] + 8) = 0;
      if ( RtlValidSid((_BYTE *)v4[1]) )
      {
        if ( PiAuAllocateAndInitializeSid(v4 + 2, (int)va, 2u) >= 0 )
        {
          *(_DWORD *)(v4[2] + 8) = 32;
          *(_DWORD *)(v4[2] + 12) = 544;
          if ( RtlValidSid((_BYTE *)v4[2]) )
          {
            if ( PiAuAllocateAndInitializeSid(v4 + 3, (int)va, 1u) >= 0 )
            {
              *(_DWORD *)(v4[3] + 8) = 2;
              if ( RtlValidSid((_BYTE *)v4[3]) )
              {
                if ( PiAuAllocateAndInitializeSid(v4 + 4, (int)va, 2u) >= 0 )
                {
                  *(_DWORD *)(v4[4] + 8) = 32;
                  *(_DWORD *)(v4[4] + 12) = 545;
                  if ( RtlValidSid((_BYTE *)v4[4]) )
                  {
                    if ( PiAuAllocateAndInitializeSid(v4 + 5, (int)va, 1u) >= 0 )
                    {
                      *(_DWORD *)(v4[5] + 8) = 19;
                      if ( RtlValidSid((_BYTE *)v4[5]) )
                      {
                        if ( PiAuAllocateAndInitializeSid(v4 + 6, (int)va, 1u) >= 0 )
                          JUMPOUT(0x95FE7C);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  JUMPOUT(0x95FE8C);
}
