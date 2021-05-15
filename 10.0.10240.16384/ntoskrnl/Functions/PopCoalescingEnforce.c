// PopCoalescingEnforce 
 
int __fastcall PopCoalescingEnforce(int result)
{
  if ( result )
  {
    if ( !PopCurrentCoalescingSpindownTimeout )
    {
      PopEnforcedCoalescingSpindownTimeout = result;
      PopCoalescingEnforced = 1;
      result = PopCoalescingActivate(1);
    }
  }
  else if ( PopCurrentCoalescingSpindownTimeout && PopCoalescingEnforced )
  {
    PopEnforcedCoalescingSpindownTimeout = 0;
    PopCoalescingEnforced = 0;
    result = PopCoalescingActivate(0);
  }
  return result;
}
