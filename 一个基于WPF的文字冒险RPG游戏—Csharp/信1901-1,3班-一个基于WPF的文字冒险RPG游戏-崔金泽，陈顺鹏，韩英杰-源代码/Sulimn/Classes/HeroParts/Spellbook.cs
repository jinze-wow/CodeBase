﻿using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;

namespace Sulimn.Classes.HeroParts
{
    /// <summary>Represents a collection of Spells a Hero can cast.</summary>
    internal class Spellbook : BaseINPC
    {
        private List<Spell> _spells = new List<Spell>();

        /// <summary>List of known Spells.</summary>
        internal ReadOnlyCollection<Spell> Spells => new ReadOnlyCollection<Spell>(_spells);

        /// <summary>List of known <see cref="Spell"/>s, set up to import from JSON.</summary>
        public string SpellsString
        {
            get => string.Join(",", Spells);
            set
            {
                _spells = new List<Spell>();
                if (!string.IsNullOrWhiteSpace(value))
                {
                    foreach (string spell in value.Split(','))
                        LearnSpell(GameState.AllSpells.Find(spl => spl.Name == spell.Trim()));
                    NotifyPropertyChanged(nameof(Spells));
                }
            }
        }

        /// <summary>Teaches a Hero a Spell.</summary>
        /// <param name="newSpell">Spell to be learned</param>
        /// <returns>String saying Hero learned the spell</returns>
        internal string LearnSpell(Spell newSpell)
        {
            _spells.Add(newSpell);
            NotifyPropertyChanged(nameof(Spells));
            return $"You learn {newSpell.Name}.";
        }

        #region Override Operators

        public static bool Equals(Spellbook left, Spellbook right)
        {
            if (left is null && right is null) return true;
            if (left is null ^ right is null) return false;
            return !left.Spells.Except(right.Spells).Any();
        }

        public sealed override bool Equals(object obj) => Equals(this, obj as Spellbook);

        public bool Equals(Spellbook otherSpellbook) => Equals(this, otherSpellbook);

        public static bool operator ==(Spellbook left, Spellbook right) => Equals(left, right);

        public static bool operator !=(Spellbook left, Spellbook right) => !Equals(left, right);

        public sealed override int GetHashCode() => base.GetHashCode() ^ 17;

        public sealed override string ToString() => string.Join(",", Spells);

        #endregion Override Operators

        #region Constructors

        /// <summary>Initializes a default instance of Spellbook.</summary>
        public Spellbook()
        {
        }

        /// <summary>Initializes a new instance of Spellbook by assigning known spells.</summary>
        /// <param name="spellList">List of known spells</param>
        public Spellbook(IEnumerable<Spell> spellList)
        {
            List<Spell> newSpells = new List<Spell>();
            newSpells.AddRange(spellList);
            _spells = newSpells;
        }

        /// <summary>Replaces this instance of Spellbook with another instance.</summary>
        /// <param name="other">Instance of Spellbook to replace this instance</param>
        public Spellbook(Spellbook other) : this(new List<Spell>(other.Spells))
        {
        }

        #endregion Constructors
    }
}