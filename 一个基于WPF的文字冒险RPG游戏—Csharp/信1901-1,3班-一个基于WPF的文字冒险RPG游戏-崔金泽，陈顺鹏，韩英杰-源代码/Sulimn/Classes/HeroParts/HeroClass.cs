﻿using System;

namespace Sulimn.Classes.HeroParts
{
    /// <summary>Represents the Class of a Hero.</summary>
    public class HeroClass : BaseINPC
    {
        private string _name, _description;
        private int _skillPoints, _strength, _vitality, _dexterity, _wisdom, _currentHealth, _maximumHealth, _currentMagic, _maximumMagic;

        #region Modifying Properties

        /// <summary>Name of the Class.</summary>
        public string Name
        {
            get => _name;
            set
            {
                _name = value;
                NotifyPropertyChanged(nameof(Name));
            }
        }

        /// <summary>Description of the Class.</summary>
        public string Description
        {
            get => _description;
            set
            {
                _description = value;
                NotifyPropertyChanged(nameof(Description));
            }
        }

        /// <summary>Maximum number of skill points a Class can have when initially being assigned.</summary>
        public int SkillPoints
        {
            get => _skillPoints;
            set
            {
                _skillPoints = value;
                NotifyPropertyChanged(nameof(SkillPoints), nameof(SkillPointsToString));
            }
        }

        /// <summary>Amount of Strength the Class has by default.</summary>
        public int Strength
        {
            get => _strength;
            set
            {
                _strength = value;
                NotifyPropertyChanged(nameof(Strength));
            }
        }

        /// <summary>Amount of Vitality the Class has by default.</summary>
        public int Vitality
        {
            get => _vitality;
            set
            {
                _vitality = value;
                CurrentHealth = Vitality * 5;
                MaximumHealth = Vitality * 5;
                NotifyPropertyChanged(nameof(Vitality));
            }
        }

        /// <summary>Amount of Dexterity the Class has by default.</summary>
        public int Dexterity
        {
            get => _dexterity;
            set
            {
                _dexterity = value;
                NotifyPropertyChanged(nameof(Dexterity));
            }
        }

        /// <summary>Amount of Wisdom the Class has by default.</summary>
        public int Wisdom
        {
            get => _wisdom;
            set
            {
                _wisdom = value;
                CurrentMagic = Wisdom * 5;
                MaximumMagic = Wisdom * 5;
                NotifyPropertyChanged(nameof(Wisdom));
            }
        }

        /// <summary>Amount of current health the Class has.</summary>
        public int CurrentHealth
        {
            get => _currentHealth;
            set
            {
                _currentHealth = value;
                NotifyPropertyChanged(nameof(CurrentHealth), nameof(HealthToString));
            }
        }

        /// <summary>Amount of maximum health the Class has.</summary>
        public int MaximumHealth
        {
            get => _maximumHealth;
            set
            {
                _maximumHealth = value;
                NotifyPropertyChanged(nameof(MaximumHealth), nameof(HealthToString));
            }
        }

        /// <summary>Amount of current magic the Class has.</summary>
        public int CurrentMagic
        {
            get => _currentMagic;
            set
            {
                _currentMagic = value;
                NotifyPropertyChanged(nameof(CurrentMagic), nameof(MagicToString));
            }
        }

        /// <summary>Amount of maximum magic the Class has.</summary>
        public int MaximumMagic
        {
            get => _maximumMagic;
            set
            {
                _maximumMagic = value;
                NotifyPropertyChanged(nameof(MaximumMagic), nameof(MagicToString));
            }
        }

        #endregion Modifying Properties

        #region Helper Properties

        /// <summary>Maximum number of skill points a Class can have when initially being assigned, with thousands separator.</summary>
        /// <summary>The amount of skill points the Hero has available to spend</summary>
        public string SkillPointsToString => SkillPoints != 1 ? $"{SkillPoints:N0} Skill Points Available" : $"{SkillPoints:N0} Skill Point Available";

        /// <summary>Amount of health the Class has, formatted.</summary>
        public string HealthToString => $"{CurrentHealth:N0} / {MaximumHealth:N0}";

        /// <summary>Amount of magic the Class has, formatted.</summary>
        public string MagicToString => $"{CurrentMagic:N0} / {MaximumMagic:N0}";

        #endregion Helper Properties

        #region Override Operators

        public static bool Equals(HeroClass left, HeroClass right)
        {
            if (left is null && right is null) return true;
            if (left is null ^ right is null) return false;
            return string.Equals(left.Name, right.Name, StringComparison.OrdinalIgnoreCase)
                   && string.Equals(left.Description, right.Description, StringComparison.OrdinalIgnoreCase)
                   && left.SkillPoints == right.SkillPoints
                   && left.Strength == right.Strength
                   && left.Vitality == right.Vitality
                   && left.Dexterity == right.Dexterity
                   && left.Wisdom == right.Wisdom
                   && left.CurrentHealth == right.CurrentHealth
                   && left.MaximumHealth == right.MaximumHealth
                   && left.CurrentMagic == right.CurrentMagic
                   && left.MaximumMagic == right.MaximumMagic;
        }

        public sealed override bool Equals(object obj) => Equals(this, obj as HeroClass);

        public bool Equals(HeroClass other) => Equals(this, other);

        public static bool operator ==(HeroClass left, HeroClass right) => Equals(left, right);

        public static bool operator !=(HeroClass left, HeroClass right) => !Equals(left, right);

        public sealed override int GetHashCode() => base.GetHashCode() ^ 17;

        public sealed override string ToString() => Name;

        #endregion Override Operators

        #region Constructors

        /// <summary>Initializes a default instance of HeroClass.</summary>
        internal HeroClass()
        {
        }

        /// <summary>Initializes an instance of HeroClass by assigning Properties.</summary>
        /// <param name="name">Name of HeroClass</param>
        /// <param name="description">Description of HeroClass</param>
        /// <param name="skillPoints">Skill Points</param>
        /// <param name="strength">Strength</param>
        /// <param name="vitality">Vitality</param>
        /// <param name="dexterity">Dexterity</param>
        /// <param name="wisdom">Wisdom</param>
        internal HeroClass(string name, string description, int skillPoints, int strength, int vitality, int dexterity,
        int wisdom)
        {
            Name = name;
            Description = description;
            SkillPoints = skillPoints;
            Strength = strength;
            Vitality = vitality;
            Dexterity = dexterity;
            Wisdom = wisdom;
        }

        /// <summary>Replaces this instance of HeroClass with another instance.</summary>
        /// <param name="other">Instance of HeroClass to replace this instance</param>
        internal HeroClass(HeroClass other) : this(other.Name, other.Description, other.SkillPoints, other.Strength,
            other.Vitality, other.Dexterity, other.Wisdom)
        {
        }

        #endregion Constructors
    }
}