// VfCheckUserHandle 
 
int __fastcall VfCheckUserHandle(int result)
{
  int v1; // r9
  _DWORD *v2; // r6
  unsigned int v3; // r5
  unsigned int v4; // r4
  int *v5; // r7
  int v6; // t1
  int v7; // r7
  int v8; // r5
  int v9; // r2
  int v10; // [sp+8h] [bp-88h] BYREF
  int v11; // [sp+Ch] [bp-84h] BYREF
  _DWORD v12[8]; // [sp+10h] [bp-80h] BYREF
  unsigned __int16 v13[48]; // [sp+30h] [bp-60h] BYREF

  v1 = result;
  if ( (MmVerifierData & 0x100) != 0 )
  {
    v2 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( PsInitialSystemProcess )
    {
      if ( v2 != (_DWORD *)PsInitialSystemProcess && v2 != (_DWORD *)PsIdleProcess )
      {
        if ( result )
        {
          result = RtlCaptureStackBackTrace(2u, 8u, (int)v12, 0);
          v3 = result;
          v4 = 0;
          if ( result )
          {
            v5 = v12;
            while ( 1 )
            {
              v6 = *v5++;
              result = v6;
              if ( !ViDriverKernelBase
                || result < (unsigned int)ViDriverKernelBase
                || result >= (unsigned int)ViDriverKernelEnd )
              {
                break;
              }
              if ( KernelVerifier )
                goto LABEL_15;
              if ( ++v4 >= v3 )
                return result;
            }
            result = VfTargetDriversIsEnabled(result, (int)&ViDriverKernelEnd);
            if ( !result )
              return result;
LABEL_15:
            if ( v4 < v3 )
            {
              result = VfUtilIsLocalSystem(v2);
              if ( !result )
              {
                result = ObReferenceObjectByHandle(v1, 0, 0, 1, (int)&v10, 0);
                v7 = v10;
                if ( result < 0 )
                  goto LABEL_23;
                v8 = 0;
                if ( ObQueryTypeName(v10, (int)v13, 0x40u, &v11) >= 0
                  && (RtlEqualUnicodeString(v13, (unsigned __int16 *)&ViDesktopTypeName, 0)
                   || RtlEqualUnicodeString(v13, (unsigned __int16 *)&ViWindowStationTypeName, 0)) )
                {
                  v8 = 1;
                }
                result = ObfDereferenceObject(v7);
                if ( !v8 )
                {
LABEL_23:
                  v9 = ViHandleBreaksEnabled;
                  __dmb(0xBu);
                  if ( v9 )
                    result = VerifierBugCheckIfAppropriate(196, 246, v1, (int)v2, v12[v4]);
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
