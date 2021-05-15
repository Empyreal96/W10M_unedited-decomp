// PspAddProcessToWorkingSetChangeList 
 
void **__fastcall PspAddProcessToWorkingSetChangeList(void **result)
{
  int v1; // r4
  _DWORD *v2; // r5
  void ***v3; // r1

  v1 = (int)result;
  if ( ((unsigned int)result[47] & 1) == 0 )
  {
    v2 = result[72];
    __dmb(0xBu);
    if ( (v2[100] & 1) != 0 )
    {
      result = (void **)ObReferenceObjectSafeWithTag((int)result);
      if ( result )
      {
        result = (void **)ExAllocatePoolWithTag(1, 20, 1917023056);
        if ( result )
        {
          result[2] = (void *)v1;
          result[4] = (void *)v2[93];
          result[3] = (void *)v2[92];
          v3 = (void ***)off_618E24;
          *result = &PspWorkingSetChangeHead;
          result[1] = v3;
          if ( *v3 != &PspWorkingSetChangeHead )
            __fastfail(3u);
          *v3 = result;
          off_618E24 = result;
        }
        else
        {
          result = (void **)ObfDereferenceObjectWithTag(v1);
        }
      }
    }
    else
    {
      result = (void **)MmEnforceWorkingSetLimit((int)result, 2);
    }
  }
  return result;
}
